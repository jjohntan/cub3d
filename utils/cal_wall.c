/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:29:11 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/25 12:25:27 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void cal_wall(int i , float angle, float *p, t_game *g)
{
    float theta;

    theta = g->angle - angle;
    if (theta < 0)
        theta *= -1;
    if (theta > FOV / 2)
        theta = DEG_360 - theta;
    g->wall[i].height = hypot(g->pos[Y] - p[Y] ,g->pos[X] - p[X]) * cos(theta);
    g->wall[i].height = (CELL /  g->wall[i].height) * PROJECTED_D;
    if (g->wall[i].height > SCREEN_H)
        g->wall[i].height = SCREEN_H;
    
    if (g->which_cal == Y_INTER)
        g->wall[i].color = WALL_1;
    else
        g->wall[i].color = WALL_2;
}