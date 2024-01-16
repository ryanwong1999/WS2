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


#include <sys/types.h>
#include <math.h>
#include <algorithm>

#include "nav2_amcl/motion_model/motion_model.hpp"
#include "nav2_amcl/angleutils.hpp"

namespace nav2_amcl
{

DifferentialMotionModel::DifferentialMotionModel(
  double alpha1, double alpha2, double alpha3,
  double alpha4)
{
  alpha1_ = alpha1;
  alpha2_ = alpha2;
  alpha3_ = alpha3;
  alpha4_ = alpha4;
}

void
DifferentialMotionModel::odometryUpdate(
  pf_t * pf, const pf_vector_t & pose,
  const pf_vector_t & delta)
{
  // Compute the new sample poses
  pf_sample_set_t * set;

  // 还通过临时变量set从里程计对象中获取粒子集合。
  // 这里设定粒子sample集由传入的粒子滤波器的粒子sample集和它的当前粒子sample集
  set = pf->sets + pf->current_set;
  // 并通过pf模块的函数pf_vector_sub，从运动数据中推算出上一时刻的里程计位姿。
  // 简单的运算，就是本时刻减去delta
  pf_vector_t old_pose = pf_vector_sub(pose, delta);

  // Implement sample_motion_odometry (Prob Rob p 136)
    // 首先定义了一堆临时变量，它们都是更新过程中需要用到的中间变量。
  double delta_rot1, delta_trans, delta_rot2;
  double delta_rot1_hat, delta_trans_hat, delta_rot2_hat;
  double delta_rot1_noise, delta_rot2_noise;

  // Avoid computing a bearing from two poses that are extremely near each
  // other (happens on in-place rotation).
  // 如果原地旋转的情况，定义第一个旋转为0，认为所有旋转都是第二个旋转做的
  // 就是xy位移小于一个值
  if (sqrt(
      delta.v[1] * delta.v[1] +
      delta.v[0] * delta.v[0]) < 0.01)
  {
    delta_rot1 = 0.0;
  } else {
    // 计算的就是new与old的theta的差值
    // 注意，这里的是delta
    // 也就是delta_x=/x'-/x,这里面的/就是x头上的——
    // 所以下面计算delta_rot2时候delta.v[2]=/theta'-/theta
    // 函数angle_diff实现了得到两个角度的差值，并取夹角小的差值。
    delta_rot1 = angleutils::angle_diff(
      atan2(delta.v[1], delta.v[0]),
      old_pose.v[2]);
  }
  delta_trans = sqrt(
    delta.v[0] * delta.v[0] +
    delta.v[1] * delta.v[1]);
  delta_rot2 = angleutils::angle_diff(delta.v[2], delta_rot1);

  // We want to treat backward and forward motion symmetrically for the
  // noise model to be applied below.  The standard model seems to assume
  // forward motion.
  // 这里作者比书本多考虑了一种情况，就是机器人旋转小角度，然后往后走的情况，比如旋转-20°，然后往后走，计算出来可能是160°，
  // 但实际只转了20°。按书本可能是比较大的方差（160°），不太准确，但这里的话还是按照比较小的方差来采样。
  // 博主认为万一真的转了160°再前向运动的话怎么办？还是用比较小的方差来采样，可能会使得采样的准确率下降。
  // 实际中，编码器采样率很高，且设定了一个很小的变化角度就进行运动模型更新，所以我说的这种情况几乎不会发生
  delta_rot1_noise = std::min(
    fabs(angleutils::angle_diff(delta_rot1, 0.0)),
    fabs(angleutils::angle_diff(delta_rot1, M_PI)));
  delta_rot2_noise = std::min(
    fabs(angleutils::angle_diff(delta_rot2, 0.0)),
    fabs(angleutils::angle_diff(delta_rot2, M_PI)));

  // 对于每一个粒子，按照书中的方法进行更新
  // 也就是按照运动模型，对粒子进行位置更新
  for (int i = 0; i < set->sample_count; i++) {
    pf_sample_t * sample = set->samples + i;

    // Sample pose differences
    // 这个就是程序的5-7行
    delta_rot1_hat = angleutils::angle_diff(
      delta_rot1,
      pf_ran_gaussian(
        sqrt(
          alpha1_ * delta_rot1_noise * delta_rot1_noise +
          alpha2_ * delta_trans * delta_trans)));
    delta_trans_hat = delta_trans -
      pf_ran_gaussian(
      sqrt(
        alpha3_ * delta_trans * delta_trans +
        alpha4_ * delta_rot1_noise * delta_rot1_noise +
        alpha4_ * delta_rot2_noise * delta_rot2_noise));
    delta_rot2_hat = angleutils::angle_diff(
      delta_rot2,
      pf_ran_gaussian(
        sqrt(
          alpha1_ * delta_rot2_noise * delta_rot2_noise +
          alpha2_ * delta_trans * delta_trans)));

    // Apply sampled update to particle pose
    // 这个就是程序的8-10行
    sample->pose.v[0] += delta_trans_hat *
      cos(sample->pose.v[2] + delta_rot1_hat);
    sample->pose.v[1] += delta_trans_hat *
      sin(sample->pose.v[2] + delta_rot1_hat);
    sample->pose.v[2] += delta_rot1_hat + delta_rot2_hat;
  }
}

}  // namespace nav2_amcl
