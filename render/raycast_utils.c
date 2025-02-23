/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:23:49 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 23:23:49 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void	update_point(t_ray *ray, float *step, int intercept)
{
	ray->x += step[X];
	ray->y += step[Y];
	ray->intercept = intercept;
}

bool	check_wall(t_ray *ray, t_game *g)
{
	char	c;
	int		x;
	int		y;

	x = ray->x / TILE;
	y = ray->y / TILE;
	if (ray->intercept == X && cos(ray->angle) < 0)
		x--;
	if (ray->intercept == Y && sin(ray->angle) < 0)
		y--;
	c = g->map.ar[y][x];
	if (c == '1' || c == 'D')
	{
		if (c == 'D')
			ray->door = true;
		else
			ray->door = false;
		return (true);
	}
	return (false);
}

float	x_intercept(float p, float angle, float *step)
{
	if (cos(angle) < 0)
	{
		step[X] = TILE * ((int)p / TILE) - p;
		if (!step[X])
			step[X] = -TILE;
	}
	else
		step[X] = TILE + TILE * ((int)p / TILE) - p;
	step[Y] = step[X] * tan(angle);
	return (hypot(step[X], step[Y]));
}

float	y_intercept(float p, float angle, float *step)
{
	if (sin(angle) < 0)
	{
		step[Y] = TILE * ((int)p / TILE) - p;
		if (!step[Y])
			step[Y] = -TILE;
	}
	else
		step[Y] = TILE + TILE * ((int)p / TILE) - p;
	step[X] = step[Y] / tan(angle);
	return (hypot(step[X], step[Y]));
}
