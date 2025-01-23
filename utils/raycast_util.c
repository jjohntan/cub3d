/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:56:44 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/23 19:56:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool y_only(float a)
{
    return ((a > 1.544 && a < 1.597) || (a > 4.686 && a < 4.736));
}

bool x_only(float a)
{
    return ((a > 6.257 || a < 0.026) || (a > 3.115 && a < 3.168));
}

int update_point(float *p ,float *step, int which_cal)
{
    p[X] += step[X];
    p[Y] += step[Y];
    return (which_cal);
}

float x_intercept(float *p, float *step, float angle)
{
    if (cos(angle) < 0)
    {
        step[X] = CELL * floor(p[X] / CELL) - p[X];
        if (!step[X])
            step[X] = -1 * CELL;
    }
    else 
        step[X] = CELL - (p[X] - CELL * floor(p[X] / CELL));
    step[Y] = step[X] * tan(angle);
    return (hypot(step[X], step[Y]));
}

float y_intercept(float *p, float *step, float angle)
{        
    if (sin(angle) < 0)
    {
        step[Y] = CELL * floor(p[Y] / CELL) - p[Y];
        if (!step[Y])
            step[Y] = -1 * CELL;
    }
    else
        step[Y] = CELL - (p[Y] - CELL * floor(p[Y] / CELL));
    step[X] = step[Y] / tan(angle);
    return (hypot(step[X], step[Y]));
}
