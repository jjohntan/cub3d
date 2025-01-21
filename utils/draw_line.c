/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:27:46 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/21 01:27:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_line(int start[2], int end[2], int color, t_game *g)
{
	int len;
    int i;
	double dx;
	double dy;
	
	dx = end[X] - start[X];
	dy = end[Y] - start[Y];
	len = hypot(dx, dy);
	dx /= len;
	dy /= len;
	i = -1;
	while (++i <= len)
		put_pixel(start[X] + i * dx, start[Y] + i * dy, color, g);
}