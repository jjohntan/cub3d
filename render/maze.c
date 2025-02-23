/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:07:47 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 11:42:22 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static void	put_tile(int x, int y, int color, t_game *g);

void	draw_maze(t_game *g)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (g->map.ar[++y])
	{
		x = -1;
		while (g->map.ar[y][++x])
		{
			c = g->map.ar[y][x];
			if (c == '1')
				put_tile(x, y, WALL, g);
			else if (c == 'D')
				put_tile(x, y, LOCK, g);
			else if (c == 'U')
				put_tile(x, y, UNLOCK, g);
			else
				put_tile(x, y, SPACE, g);
		}
	}
}

static void	put_tile(int x, int y, int color, t_game *g)
{
	int	x_max;
	int	x_min;
	int	y_max;

	x_max = x * TILE + TILE;
	y_max = y * TILE + TILE;
	x_min = x * TILE;
	y = y * TILE;
	while (++y < y_max - 1)
	{
		x = x_min;
		while (++x < x_max - 1)
			putpx_disp(x, y, color, g);
	}
}
