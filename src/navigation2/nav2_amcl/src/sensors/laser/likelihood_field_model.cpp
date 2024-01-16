/*
 *  Player - One Hell of a Robot Server
 *  Copyright (C) 2000  Brian Gerkey   &  Kasper Stoy
 *                      gerkey@usc.edu    kaspers@robotics.usc.edu
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <math.h>
#include <assert.h>

#include "nav2_amcl/sensors/laser/laser.hpp"

namespace nav2_amcl
{

LikelihoodFieldModel::LikelihoodFieldModel(
  double z_hit, double z_rand, double sigma_hit,
  double max_occ_dist, size_t max_beams, map_t * map)
: Laser(max_beams, map)
{
  z_hit_ = z_hit;
  z_rand_ = z_rand;
  sigma_hit_ = sigma_hit;
  // 广度优先搜索，然后得到势场，即距离最近障碍物的距离，更新的是this->map
  map_update_cspace(map, max_occ_dist);
}

double
LikelihoodFieldModel::sensorFunction(LaserData * data, pf_sample_set_t * set)
{
  LikelihoodFieldModel * self;
  int i, j, step;
  double z, pz;
  double p;
  double obs_range, obs_bearing;
  double total_weight;
  pf_sample_t * sample; // 第几个粒子的指针
  pf_vector_t pose;     // 第几个粒子对应的上map下laser_link位姿
  pf_vector_t hit;      // 激光点在map坐标系下的位姿

  self = reinterpret_cast<LikelihoodFieldModel *>(data->laser);

  total_weight = 0.0;

  // Compute the sample weights
  // 计算所有样本点的权重
  // 遍历所有的粒子集
  for (j = 0; j < set->sample_count; j++) {
    sample = set->samples + j;
    // 遍历每个粒子，这是粒子对应的位姿，是经运动模型更新后先验位姿
    pose = sample->pose;

    // Take account of the laser pose relative to the robot
    // 这个应该是通过机器人与全局坐标系的位姿（每个粒子的位姿），
    // 计算激光雷达相对于全局坐标系的位姿。
    // 方便后续将激光雷达扫描的终点转换到全局坐标系
    // 点进去pf_vector_coord_add这个函数，
    // b（pose）对应的就是《概率机器人》P128,6.4第一个公式中的机器人在t时刻的位姿，
    // a（laser_pose）代表“与机器人固连的传感器局部坐标系位置”。就是传感器相对于机器人坐标系的位置
    // 这个函数就是将传感器的位置laser_pose转化到全局坐标系下
    // 所以pose就是传感器在全局坐标系的位置
    pose = pf_vector_coord_add(self->laser_pose_, pose);

    p = 1.0;

    // Pre-compute a couple of things
    // 测量噪声的方差
    double z_hit_denom = 2 * self->sigma_hit_ * self->sigma_hit_;
    // 无法解释的随机测量误差
    double z_rand_mult = 1.0 / data->range_max;

    // 每隔多少光束，计算一次
    step = (data->range_count - 1) / (self->max_beams_ - 1);

    // Step size must be at least 1
    if (step < 1) {
      step = 1;
    }

    // 对雷达数据进行遍历
    // 因为时间问题，并不是全部点都进行似然计算的，这里只是间隔地选点，
    // 就是每个几个点进行一下似然计算
    // 这个就相当于CSM了，进行全匹配
    for (i = 0; i < data->range_count; i += step) {
      // 这两个参数应该就是雷达扫描点的距离和相对于雷达的角度
      obs_range = data->ranges[i][0];
      obs_bearing = data->ranges[i][1];

      // This model ignores max range readings
      if (obs_range >= data->range_max) {
        continue;
      }

      // Check for NaN
      if (obs_range != obs_range) {
        continue;
      }

      pz = 0.0;

      // Compute the endpoint of the beam
      // 求出来雷达点的最远端在全局坐标系的位置
      // 这个就是第5-6行  注意这里的pose已经进行了计算，不是单纯的xy，而是x+xksenscos(theta)-yxsenssin(theta)
      // 这个角度还是有一点的懵，总感觉这里多算了一个角度，就是pf_vector_coord_add中加了一个a.v[2]的角度
      hit.v[0] = pose.v[0] + obs_range * cos(pose.v[2] + obs_bearing);
      hit.v[1] = pose.v[1] + obs_range * sin(pose.v[2] + obs_bearing);

      // Convert to map grid coords.
      // 将这个位置转化成栅格地图中的坐标
      int mi, mj;
      mi = MAP_GXWX(self->map_, hit.v[0]);
      mj = MAP_GYWY(self->map_, hit.v[1]);

      // Part 1: Get distance from the hit to closest obstacle.
      // Off-map penalized as max distance
      // 这是提前计算好的最近距离，计算函数在map_cspace.cpp的map_update_cspace中实现遍历计算，
      // 该函数是被AMCLLaser::SetModelLikelihoodField调用
      // 第7行 这个z就是dist
      if (!MAP_VALID(self->map_, mi, mj)) {
        z = self->map_->max_occ_dist;
      } else {
        z = self->map_->cells[MAP_INDEX(self->map_, mi, mj)].occ_dist;
      }
      // Gaussian model
      // NOTE: this should have a normalization of 1/(sqrt(2pi)*sigma)
      // NOTE: 应该有一个 1/(sqrt(2pi)*sigma)，可能是直接放在了z_hit中
      // 这个是测量噪声 z_hit需要预先给 如果是z为0，概率就是1      
      pz += self->z_hit_ * exp(-(z * z) / z_hit_denom);
      // Part 2: random measurements
      // 这个是无法解释的随机噪声 z_rand需要预先给
      pz += self->z_rand_ * z_rand_mult;

      // TODO(?): outlier rejection for short readings

      assert(pz <= 1.0);
      assert(pz >= 0.0);
      //      p *= pz;
      // here we have an ad-hoc weighting scheme for combining beam probs
      // works well, though...
      // 在这里，我们有一个特殊的加权方案，可以很好地结合光束问题。
      // 然后就不用p *= pz了
      p += pz * pz * pz;
    }

    // 一个粒子的权重
    sample->weight *= p;
    // 所有粒子的权重（概率）和
    total_weight += sample->weight;
  }

  return total_weight;
}


bool
LikelihoodFieldModel::sensorUpdate(pf_t * pf, LaserData * data)
{
  if (max_beams_ < 2) {
    return false;
  }
  pf_update_sensor(pf, (pf_sensor_model_fn_t) sensorFunction, data);

  return true;
}

}  // namespace nav2_amcl
