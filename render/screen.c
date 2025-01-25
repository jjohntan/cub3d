/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:12:32 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/25 12:25:12 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void screen(t_game *g)
{
    int i = -1;
    int offset;

    draw_rect(
        (int []){512, 0},
        (int []){512 + SCREEN_W - 1, (SCREEN_H / 2) - 1},
        SKY, g);
    
     draw_rect(
        (int []){512, SCREEN_H / 2},
        (int []){512 + SCREEN_W - 1, SCREEN_H - 1},
        FLOOR, g);
    
    while (++i < SCREEN_W)
    {
        offset = SCREEN_H / 2 - g->wall[i].height / 2;
        draw_line(
            (int []){512 + i, offset},
            (int []){512 + i , offset + g->wall[i].height},
            g->wall[i].color, g);
    }
}