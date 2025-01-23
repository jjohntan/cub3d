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

void translation_motion(int key, t_game *g)
{
    if (key == UP)
    {
        g->pos[X] += g->dir[X] * MV_STEP;
        g->pos[Y] += g->dir[Y] * MV_STEP;
    }   
    else if (key == DOWN)
    {
        g->pos[X] -= g->dir[X] * MV_STEP;
        g->pos[Y] -= g->dir[Y] * MV_STEP;
    }    
    else if (key == LEFT)
    {
        g->pos[X] += g->dir[Y] * MV_STEP;
        g->pos[Y] -= g->dir[X] * MV_STEP;
    }    
    else if (key == RIGHT)
    {
        g->pos[X] -= g->dir[Y] * MV_STEP;
        g->pos[Y] += g->dir[X] * MV_STEP;
    }
}

int keyboard(int key, t_game *g)
{
    if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
        translation_motion(key, g);
    else if (key == AW_LEFT || key == AW_RIGHT)  
    {
        if (key == AW_LEFT)        g->angle -= RT_STEP;
        else if (key == AW_RIGHT)  g->angle += RT_STEP;
        g->dir[X] = cos(g->angle);
        g->dir[Y] = sin(g->angle);
    }
    limit_range(g);
    return (0);
}

void limit_range(t_game *g)
{
    if      (g->pos[X] >= W)  g->pos[X] = W - 1;
    else if (g->pos[X] < 0)   g->pos[X] = 0;

    if      (g->pos[Y] >= H)  g->pos[Y] = H - 1;
    else if (g->pos[Y] < 0)   g->pos[Y] = 0;

    if      (g->angle >= DEG_360)   g->angle -= DEG_360;
    else if (g->angle < 0)          g->angle += DEG_360;
}
