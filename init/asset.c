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
void download_img(t_game *g);
bool validate_download(t_game *g);
void get_img_address(t_game *g);

//----------------------------------------------------------------------------

void get_asset(t_game *g)
{
    download_img(g);
    if (validate_download(g))
    {
        err_msg("Fail to load all images");
        closewind(g);
    }
    get_img_address(g);
}

void download_img(t_game *g)
{
    t_img i;

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

    g->texture[0].ptr = mlx_xpm_file_to_image(g->mlx, IMG_NORTH, &i.w, &i.h);
    g->texture[1].ptr = mlx_xpm_file_to_image(g->mlx, IMG_SOUTH, &i.w, &i.h);
    g->texture[2].ptr = mlx_xpm_file_to_image(g->mlx, IMG_EAST, &i.w, &i.h);
    g->texture[3].ptr = mlx_xpm_file_to_image(g->mlx, IMG_WEST, &i.w, &i.h);
    g->texture[4].ptr = mlx_xpm_file_to_image(g->mlx, IMG_DOOR, &i.w, &i.h);
    g->texture[5].end = true;
}

bool validate_download(t_game *g)
{
    int x;
    int y;

    y = -1;
    while (!g->texture[++y].end)
    {
        if (!g->texture[y].ptr)
            return (true);
    }
    y = -1;
    while (++y < 2)
    {
        x = -1;
        while (!g->weapon[y][++x].end)
        {
            if (!g->weapon[y][x].ptr)
                return (true);
        }
    }
    return (false);
}

void get_img_address(t_game *g)
{
    int x;
    int y;
    t_img i;

    y = -1;
    while (++y < 2)
	{
		x = -1;
		while (!g->weapon[y][++x].end)
        {
			g->weapon[y][x].buf = (int *)mlx_get_data_addr(g->weapon[y][x].ptr
                , &i.bpp, &i.row, &i.end);
        }
	}
    y = -1;
    while (!g->texture[++y].end)
    {
        g->texture[y].buf = (int *)mlx_get_data_addr(g->texture[y].ptr
            , &i.bpp, &i.row, &i.end);
    }
}
