/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:17:12 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/19 12:17:12 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init(t_game *g)
{	
	g->width = 1024;
	g->height = 512;
	
	g->xpos = 100;
	g->ypos = 180;
	g->mv_step = 4.0;
	
	g->angle = NORTH;
	g-> rt_step = 0.1;
	g->xdir = cos(g->angle);
    g->ydir = sin(g->angle);

	g->mlx = mlx_init();
	g->wind = mlx_new_window(g->mlx, g->width, g->height, "Cub3D");

	g->map[0] = "11111111";
	g->map[1] = "10000001";
	g->map[2] = "10000001";
	g->map[3] = "10101101";
	g->map[4] = "10000001";
	g->map[5] = "10101111";
	g->map[6] = "10000001";
	g->map[7] = "11111111";
	g->map[8] = NULL;

	g->grid = 64;
}
