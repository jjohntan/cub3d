/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:56:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/31 19:56:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void draw_player(t_game *g)
{
   int i;

   i = -1;
   while (++i < WIND_W)
   {
        draw_line(
            (int []){g->p1.x, g->p1.y},
            (int []){g->ray[i].x, g->ray[i].y},
            P1_FOV, g);
   }
    draw_circle(
        (int []){g->p1.x, g->p1.y},
        7, P1_POS, g);
}
