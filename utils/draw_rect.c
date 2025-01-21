/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:27:43 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/21 01:27:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_rect(int start[2], int end[2], int color, t_game *g)
{
	int x;
	int y;

	y = start[Y] - 1;
	while (++y <= end[Y])
	{
		x = start[X];
		while (x <= end[X])
			put_pixel(x++, y, color, g);
	}
}