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
/**************************************************************************
 * Desc: KD tree functions
 * Author: Andrew Howard
 * Date: 18 Dec 2002
 * CVS: $Id: pf_kdtree.h 6532 2008-06-11 02:45:56Z gbiggs $
 *************************************************************************/

// 定义一个kdtree以及维护方法来管理所有的粒子(粒子在这里表征位姿和权重)
#ifndef NAV2_AMCL__PF__PF_KDTREE_HPP_
#define NAV2_AMCL__PF__PF_KDTREE_HPP_

#ifdef INCLUDE_RTKGUI
#include <rtk.h>
#endif


// Info for a node in the tree
// 树中一个节点
typedef struct pf_kdtree_node
{
  // Depth in the tree
  int leaf, depth;

  // Pivot dimension and value
  // 就是从哪一个维度开始分割，即x、y、theta
  int pivot_dim;
  double pivot_value; // 分叉的值

  // The key for this node
  int key[3];

  // The value for this node
  double value;

  // The cluster label (leaf nodes)
  // 把叶子节点进行聚类，形成多个子类，然后每个叶子节点存储着它属于那个子类
  int cluster;

  // Child nodes
  // 左边是小值，右边是大值
  struct pf_kdtree_node * children[2];
} pf_kdtree_node_t;


// A kd tree
// 一个kd树
typedef struct
{
  // Cell size
  // 就是把值扩大，加入输入1，这个值是0.5，那么就是2
  double size[3];

  // The root node of the tree
  pf_kdtree_node_t * root;

  // The number of nodes in the tree
  int node_count, node_max_count;
  pf_kdtree_node_t * nodes;

  // The number of leaf nodes in the tree
  // kd树的叶节点
  int leaf_count;
} pf_kdtree_t;


// Create a tree
extern pf_kdtree_t * pf_kdtree_alloc(int max_size);

// Destroy a tree
extern void pf_kdtree_free(pf_kdtree_t * self);

// Clear all entries from the tree
extern void pf_kdtree_clear(pf_kdtree_t * self);

// Insert a pose into the tree
extern void pf_kdtree_insert(pf_kdtree_t * self, pf_vector_t pose, double value);

// Cluster the leaves in the tree
extern void pf_kdtree_cluster(pf_kdtree_t * self);

// Determine the probability estimate for the given pose
extern double pf_kdtree_get_prob(pf_kdtree_t * self, pf_vector_t pose);

// Determine the cluster label for the given pose
extern int pf_kdtree_get_cluster(pf_kdtree_t * self, pf_vector_t pose);


#ifdef INCLUDE_RTKGUI

// Draw the tree
extern void pf_kdtree_draw(pf_kdtree_t * self, rtk_fig_t * fig);

#endif

#endif  // NAV2_AMCL__PF__PF_KDTREE_HPP_
