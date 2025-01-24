/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:29:11 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/24 15:57:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define LIMIT 5.70723 // 327 degree 

void cal_wall(int i , float angle, float *p, t_game *g)
{
    float theta;

    if (g->angle >= LIMIT && angle > DEG_270)
        theta = abs(g->angle - (DEG_360 - angle));
    else
        theta = abs(g->angle - angle);
    
}