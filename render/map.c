/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:16:09 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/21 11:16:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_cell(int x, int y, int color, t_game *g)
{
    int offset;

    offset = CELL - 1;
    draw_rect(
        (int []){x + 1, y + 1},
        (int []){x + offset, y + offset},
        color, g);
}

void map(t_game *g)
{
    int x; 
    int y;
    
    y = -1;  
    while (g->map[++y])
    {
        x = 0;
        while (g->map[y][x])
        {
            if (g->map[y][x] == '1')
                draw_cell(x * CELL, y * CELL, WHITE, g);
            else
                draw_cell(x * CELL, y * CELL, BLACK, g);
            x++;
        }
    }
}