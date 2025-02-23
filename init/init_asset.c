/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:56:49 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 13:15:27 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static void	download_img(t_game *g);
static bool	validate_download(t_game *g);
static void	get_img_address(t_game *g);

/*
init_asset
=============================================================================
- create the mlx image obj using the image.path
- validate the all image obj create, throw error and exit if otherwise
- Lastly, get each img buffer address
*/
void	init_asset(t_game *g)
{
	download_img(g);
	if (!validate_download(g))
	{
		err_msg("Fail to download all images", NULL, NULL);
		closewind(g);
	}
	get_img_address(g);
}

static void	download_img(t_game *g)
{
	t_img	i;

	g->weapon[0][0].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_0, &i.w, &i.h);
	g->weapon[0][1].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_1, &i.w, &i.h);
	g->weapon[0][2].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_2, &i.w, &i.h);
	g->weapon[0][3].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_3, &i.w, &i.h);
	g->weapon[0][4].end = true;
	g->weapon[1][0].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_0, &i.w, &i.h);
	g->weapon[1][1].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_1, &i.w, &i.h);
	g->weapon[1][2].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_2, &i.w, &i.h);
	g->weapon[1][3].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_3, &i.w, &i.h);
	g->weapon[1][4].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_4, &i.w, &i.h);
	g->weapon[1][5].end = true;
	g->txt[0].ptr = mlx_xpm_file_to_image(g->mlx, g->info[NO], &i.w, &i.h);
	g->txt[1].ptr = mlx_xpm_file_to_image(g->mlx, g->info[SO], &i.w, &i.h);
	g->txt[2].ptr = mlx_xpm_file_to_image(g->mlx, g->info[EA], &i.w, &i.h);
	g->txt[3].ptr = mlx_xpm_file_to_image(g->mlx, g->info[WE], &i.w, &i.h);
	g->txt[4].ptr = mlx_xpm_file_to_image(g->mlx, IMG_DOOR, &i.w, &i.h);
	g->txt[5].end = true;
}

static bool	validate_download(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (!g->txt[++y].end)
	{
		if (!g->txt[y].ptr)
			return (false);
	}
	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (!g->weapon[y][++x].end)
		{
			if (!g->weapon[y][x].ptr)
				return (false);
		}
	}
	return (true);
}

static void	get_img_address(t_game *g)
{
	int		x;
	int		y;
	t_img	i;

	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (!g->weapon[y][++x].end)
		{
			g->weapon[y][x].buf = (int *)mlx_get_data_addr(
					g->weapon[y][x].ptr, &i.bpp, &i.row, &i.end);
		}
	}
	y = -1;
	while (!g->txt[++y].end)
	{
		g->txt[y].buf = (int *)mlx_get_data_addr(
				g->txt[y].ptr, &i.bpp, &i.row, &i.end);
	}
}
