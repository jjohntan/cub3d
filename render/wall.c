/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:59:58 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 21:59:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void put_wall_slice(int i, int col, int *buf, t_game *g)
{
    int h;
    int y;
    int offset;
    int color;

    y = -1;    
    h = g->ray[i].wall_h;
    offset = (WIND_H / 2) - (h / 2);
    while (++y < h)
    {
        if ((offset + y) >= 0 && (offset + y) < WIND_H)
        {
            color = buf[((TILE * y) / h)  * TILE + col];
            putpx_disp(i, offset + y, color, g);
        }
        else if ((offset + y) == WIND_H)
            break;
    }
}

void draw_wall(t_game *g)
{
    int i;
    int *buf;
    int col;

    i = -1;
    while (++i < WIND_W)
    {
        buf = g->texture[g->ray[i].whichtx].buf;
        if (g->ray[i].intercept == Y)
            col = (int)g->ray[i].x % TILE;
        else
            col = (int)g->ray[i].y % TILE;
        put_wall_slice(i, col, buf, g);
    }
}
