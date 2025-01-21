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

int render(t_game *d)
{
	void *canvas;

	canvas = mlx_new_image(d->mlx, d->width, d->height);
	d->buff = (int *)mlx_get_data_addr(canvas, &d->bpp, &d->row, &d->endian);
	draw_on_canvas(d);
	mlx_put_image_to_window(d->mlx, d->wind, canvas, 0, 0);
	if (d->display)
		mlx_destroy_image(d->mlx, d->display);
	d->display = canvas;
	return (0);
}

void draw_on_canvas(t_game *g)
{
	background(g);
	map(g);
	player(g);
	raycast(g);
}