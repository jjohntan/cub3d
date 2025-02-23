/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:33:23 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/30 12:33:23 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/*
void draw_line(int p[2], int end[2], int color, t_game *g)
{
    int i;
	float len;
	float dy;
	float dx;
	
	i = -1;
	len = hypot(end[X] - p[X], end[Y] - p[Y]);
	dx = (end[X] - p[X]) / len;
	dy = (end[Y] - p[Y]) / len;
	while (++i <= (int)len)
		putpx_disp(p[X] + round(i * dx), p[Y] + round(i * dy), color, g);
}
*/

void	init_bresenham(int *d, int *s, int *p, int *end)
{
	d[X] = abs(end[X] - p[X]);
	d[Y] = abs(end[Y] - p[Y]);
	if (p[X] < end[X])
		s[X] = 1;
	else
		s[X] = -1;
	if (p[Y] < end[Y])
		s[Y] = 1;
	else
		s[Y] = -1;
}

void	draw_line(int p[2], int end[2], int color, t_game *g)
{
	int	d[2];
	int	s[2];
	int	err;
	int	e2;

	init_bresenham(d, s, p, end);
	err = d[X] - d[Y];
	while (true)
	{
		putpx_disp(p[X], p[Y], color, g);
		if (p[Y] == end[Y] && p[X] == end[X])
			break ;
		e2 = 2 * err;
		if (e2 > -d[Y])
		{
			err -= d[Y];
			p[X] += s[X];
		}
		if (e2 < d[X])
		{
			err += d[X];
			p[Y] += s[Y];
		}
	}
}
