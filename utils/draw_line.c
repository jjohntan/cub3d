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
