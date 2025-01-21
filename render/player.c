/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:13 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/21 10:14:13 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void player(t_game *g)
{
    draw_line(
        (int []){g->xpos, g->ypos},
        (int []){g->xpos + g->xdir * 7, g->ypos + g->ydir * 7},
        YELLOW, g);
    
    draw_line(
        (int []){g->xpos + g->ydir * 4, g->ypos - g->xdir * 4},
        (int []){g->xpos - g->ydir * 4, g->ypos + g->xdir * 4},
        YELLOW, g);
}