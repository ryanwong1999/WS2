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
 * Desc: Global map (grid-based)
 * Author: Andrew Howard
 * Date: 6 Feb 2003
 * CVS: $Id: map.c 1713 2003-08-23 04:03:43Z inspectorg $
**************************************************************************/

// 地图的基本操作类，主要还是就是根据世界坐标得到cell的指针：map_get_cell
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "nav2_amcl/map/map.hpp"


// Create a new map
// 创建一个新的map
map_t * map_alloc(void)
{
  map_t * map;

  map = (map_t *) malloc(sizeof(map_t));

  // Assume we start at (0, 0)
  map->origin_x = 0;
  map->origin_y = 0;

  // Make the size odd
  map->size_x = 0;
  map->size_y = 0;
  map->scale = 0;

  // Allocate storage for main map
  map->cells = (map_cell_t *) NULL;

  return map;
}


// Destroy a map
void map_free(map_t * map)
{
  free(map->cells);
  free(map);
}


// Get the cell at the given point
// 就是得到这个点所对应的cell（即指针）
map_cell_t * map_get_cell(map_t * map, double ox, double oy, double oa)
{
  (void)oa;
  int i, j;
  map_cell_t * cell;

  i = MAP_GXWX(map, ox);
  j = MAP_GYWY(map, oy);

  if (!MAP_VALID(map, i, j)) {
    return NULL;
  }

  // MAP_INDEX 二维转一维
  // map->cells：表示首指针
  cell = map->cells + MAP_INDEX(map, i, j);
  return cell;
}
