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

void get_asset(t_game *g)
{
    int x;
    int y;
    t_img i;

    g->weapon[0][0].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_0, &i.w, &i.h);
    g->weapon[0][1].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_1, &i.w, &i.h);
    g->weapon[0][2].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_2, &i.w, &i.h);
    g->weapon[0][3].ptr = mlx_xpm_file_to_image(g->mlx, KNIFE_3, &i.w, &i.h);
    g->weapon[0][4].ptr = NULL;

    g->weapon[1][0].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_0, &i.w, &i.h);
    g->weapon[1][1].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_1, &i.w, &i.h);
    g->weapon[1][2].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_2, &i.w, &i.h);
    g->weapon[1][3].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_3, &i.w, &i.h);
    g->weapon[1][4].ptr = mlx_xpm_file_to_image(g->mlx, PISTOL_4, &i.w, &i.h);
    g->weapon[1][5].ptr = NULL;

   	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (g->weapon[y][++x].ptr)
			g->weapon[y][x].buf = (int *)mlx_get_data_addr(g->weapon[y][x].ptr
                , &i.bpp, &i.row, &i.end);
	}
}
