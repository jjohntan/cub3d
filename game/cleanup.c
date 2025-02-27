/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:27:58 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/26 13:02:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

int	closewind(t_game *g)
{
	free_map(g->map.ar);
	free_info(g);
	free_asset(g);
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

void	free_asset(t_game *g)
{
	int	x;
	int	y;

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
	while (!g->txt[++y].end)
	{
		if (g->txt[y].ptr)
			mlx_destroy_image(g->mlx, g->txt[y].ptr);
	}
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_info(t_game *g)
{
	if (g->no)
		free(g->no);
	if (g->so)
		free(g->so);
	if (g->we)
		free(g->we);
	if (g->ea)
		free(g->ea);
	if (g->f)
		free(g->f);
	if (g->c)
		free(g->c);
}
