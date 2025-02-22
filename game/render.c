/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:30:32 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 13:42:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static void draw_on_canvas(t_game *g)
{
    raycast(g);
    if (g->view)
    {   
        draw_maze(g);
        draw_player(g);
    }
    else
    {
        draw_bg(g);
        draw_wall(g);
        draw_minimap(g);
        draw_weapon(g);
    }
}

int render(t_game *g)
{
    t_img i;
    void *canvas;

    canvas = mlx_new_image(g->mlx, WIND_W, WIND_H);
    g->disp.buf = (int *)mlx_get_data_addr(canvas, &i.bpp, &i.row, &i.end);
    draw_on_canvas(g);
    mlx_put_image_to_window(g->mlx, g->wind, canvas, 0, 0);
    if (g->disp.ptr)
        mlx_destroy_image(g->mlx, g->disp.ptr);
    g->disp.ptr = canvas;
    return (0);
}
