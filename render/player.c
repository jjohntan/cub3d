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
    int a[2];
    int b[2];
    int r;

    r = 40;
    a[X] = g->p1.x + r * cos(angle_limit(g->p1.angle - PI / 12));
    a[Y] = g->p1.y + r * sin(angle_limit(g->p1.angle - PI / 12));
    b[X] = g->p1.x + r * cos(angle_limit(g->p1.angle + PI / 12));
    b[Y] = g->p1.y + r * sin(angle_limit(g->p1.angle + PI / 12));

    
    draw_triangle(
        (int []){g->p1.x, a[X], b[X]},
        (int []){g->p1.y, a[Y], b[Y]},
        P1_FOV, g);

    draw_circle(
        (int []){g->p1.x, g->p1.y},
        7, P1_POS, g);
}
