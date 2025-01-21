/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:29 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/20 16:29:18 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int mouse(int x, int y, t_game *d)
{
    d->xpoint = x;
    d->ypoint = y;
    return (0);
}

int keyboard(int key, t_game *g)
{
    if (key == UP)
    {
        g->xpos += g->xdir * g->mv_step;
        g->ypos += g->ydir * g->mv_step;
    }   
    else if (key == DOWN)
    {
        g->xpos -= g->xdir * g->mv_step;
        g->ypos -= g->ydir * g->mv_step;
    }    
    else if (key == LEFT)
    {
        g->xpos += g->ydir * g->mv_step;
        g->ypos -= g->xdir * g->mv_step;
    }    
    else if (key == RIGHT)
    {
        g->xpos -= g->ydir * g->mv_step;
        g->ypos += g->xdir * g->mv_step;
    }
    else if (key == AW_LEFT || key == AW_RIGHT)  
    {
        if (key == AW_LEFT)   g->angle -= g->rt_step;
        if (key == AW_RIGHT)  g->angle += g->rt_step;
        g->xdir = cos(g->angle);
        g->ydir = sin(g->angle);
    }
    limit_range(g);
    printf("X: %f , Y: %f  Angle: %f\n", g->xpos, g->ypos, g->angle);
    return (0);
}

void limit_range(t_game *g)
{
    if      (g->xpos >= g->width)  g->xpos = g->width - 1;
    else if (g->xpos < 0)          g->xpos = 0;

    if      (g->ypos >= g->height)  g->ypos = g->height - 1;
    else if (g->ypos < 0)           g->ypos = 0;

    if      (g->angle >= REV)       g->angle -= REV;
    else if (g->angle < 0)          g->angle += REV;
}
