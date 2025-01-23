/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:18:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/19 12:18:54 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int render(t_game *g)
{
	void *canvas;

	canvas = mlx_new_image(g->mlx, W, H);
	g->buff = (int *)mlx_get_data_addr(canvas, &g->bpp, &g->row, &g->endian);
	draw_on_canvas(g);
	mlx_put_image_to_window(g->mlx, g->wind, canvas, 0, 0);
	if (g->display)
		mlx_destroy_image(g->mlx, g->display);
	g->display = canvas;
	return (0);
}

void draw_on_canvas(t_game *g)
{
	background(g);
	map(g);
	player(g);
	raycast(g);
}