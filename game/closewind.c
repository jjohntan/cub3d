/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closewind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:15:22 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 12:44:23 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
void destroy_maze(t_game *g);
void destroy_asset(t_game *g);

//----------------------------------------------------------------------------

int closewind(t_game *g)
{
	destroy_maze(g);
	destroy_asset(g);
	
	if (g->mini.ptr)
		mlx_destroy_image(g->mlx, g->mini.ptr);
	if (g->disp.ptr)
		mlx_destroy_image(g->mlx, g->disp.ptr);
	
	mlx_destroy_window(g->mlx, g->wind);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void destroy_asset(t_game *g)
{
	int x;
	int y;

	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (!g->weapon[y][++x].end)
		{
			if (g->weapon[y][x].ptr)
				mlx_destroy_image(g->mlx, g->weapon[y][x].ptr);
		}
	}
	y = -1;
	while (!g->texture[++y].end)
	{
		if (g->texture[y].ptr)
			mlx_destroy_image(g->mlx, g->texture[y].ptr);
	}
}

void destroy_maze(t_game *g)
{
    freelist(g->maze.arr);
}
