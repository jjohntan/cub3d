/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:15:38 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 22:15:38 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static void find_hit_point(t_ray *ray, t_game *g);
static void get_wall_info(t_ray *ray, t_game *g);

//----------------------------------------------------------------------------

void raycast(t_game *g)
{
    int i;
    float angle;

    i = -1;
    angle = angle_limit(g->p1.angle - (FOV / 2));
    while(++i < WIND_W)
    {
        g->ray[i].angle = angle;
        g->ray[i].x = g->p1.x;
        g->ray[i].y = g->p1.y;
        find_hit_point(&g->ray[i], g);
        get_wall_info(&g->ray[i], g);
        angle = angle_limit(angle + STEP);
    }
}

static void find_hit_point(t_ray *ray, t_game *g)
{
    float ystep[2];
    float xstep[2];

    while (true)
    {
        if (x_intercept(ray->x, ray->angle, xstep) >
            y_intercept(ray->y, ray->angle, ystep))
            update_point(ray, ystep, Y);
        else
            update_point(ray, xstep, X);
        if (check_wall(ray, g))
            break;
    }
}

static void get_wall_info(t_ray *ray, t_game *g)
{
    float correct_d;
    float angle_diff;

    if (ray->door)
        ray->which_tx = DOOR;
    else if (ray->intercept == Y && sin(ray->angle) < 0)
        ray->which_tx = NORTH;
    else if (ray->intercept == Y)
        ray->which_tx = SOUTH;
    else if (ray->intercept == X && cos(ray->angle) < 0)
        ray->which_tx = WEST;
    else
        ray->which_tx = EAST;

    angle_diff = fabs(g->p1.angle - ray->angle);
    if (angle_diff > (FOV / 2))
        angle_diff = DEG_360 - angle_diff;
    correct_d = hypot(ray->x - g->p1.x, ray->y - g->p1.y) * cos(angle_diff);
    ray->wall_h = (TILE / correct_d) * PROJECTED_D;
}

