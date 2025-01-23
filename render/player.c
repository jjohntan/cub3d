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
        (int []){g->pos[X], g->pos[Y]},
        (int []){g->pos[X] + g->dir[X] * 7, g->pos[Y] + g->dir[Y] * 7},
        YELLOW, g);
    draw_line(
        (int []){g->pos[X] + g->dir[Y] * 4, g->pos[Y] - g->dir[X] * 4},
        (int []){g->pos[X] - g->dir[Y] * 4, g->pos[Y] + g->dir[X] * 4},
        YELLOW, g);
}