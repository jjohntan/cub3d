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

void put_wall_slice(int i, int h, int color, t_game *g)
{
    int offset;

    offset = (WIND_H / 2) - (h / 2);
     draw_line(
        (int []){i, offset},
        (int []){i, offset + h},
        color, g);
}

void draw_wall(t_game *g)
{
    int i;

    i = -1;
    while (++i < WIND_W)
    {
        if (g->ray[i].whichtx == DOOR)
            put_wall_slice(i, g->ray[i].wall_h, WALL_1, g);
        else if (g->ray[i].whichtx == NORTH)
            put_wall_slice(i, g->ray[i].wall_h, WALL_2, g);
        else if (g->ray[i].whichtx == SOUTH)
            put_wall_slice(i, g->ray[i].wall_h, WALL_3, g);
        else if (g->ray[i].whichtx == EAST)
            put_wall_slice(i, g->ray[i].wall_h, WALL_4, g);
        else if (g->ray[i].whichtx == WEST)
            put_wall_slice(i, g->ray[i].wall_h, WALL_5, g);
    }
}
