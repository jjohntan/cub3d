/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:22 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/21 18:35:25 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void raycast(t_game *g)
{
    int y;
    int x;
    float px_old;
    float px_new;

    if (g->angle >= PI)
        y = (int)(g->ypos / g->grid);
    else
        y = (int)(g->ypos / g->grid) + 1;
    px_new = (y * g->grid - g->ypos) / tan(g->angle) + g->xpos;


    x = px_new / g->grid;
    while (g->map[y][x] != '1')
    {
        px_old = px_new;
        y--;
        
        px_new

    }
}
