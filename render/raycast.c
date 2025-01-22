/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:22 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/22 13:18:22 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_wall(int p[2], t_game *g)
{
    int x;
    int y;

    x = p[X] / g->grid;
    y = p[Y] / g->grid;

    if (g->side == HL && g->angle > PI)
        y--;
    else if (g->side == VL && g->angle > Q1_REV && g->angle <= Q3_REV)
        x--;
    if (g->map[y][x] == '1')
        return (true);
    return (false);
}


void raycast(t_game *g)
{
    int dy;
    int dx;
    float p[2];
    int cell = g->grid;

    p[X] = g->xpos;
    p[Y] = g->ypos;
    
    if (g->angle > Q1_REV && g->angle <= Q3_REV)
    {
        dx = floor(p[X] / cell) * cell - p[X];
        if (!dx)
            dx = -1 *cell;
    }
    else 
        dx = cell - (p[X] - floor(p[X] / cell) * cell);


    if (g->angle > PI)
    {
        dy = floor(p[Y] / cell) * cell - p[Y];
        if (!dy)
            dy = -1 * cell;
    }
    else
        dy = cell - (p[Y] - floor(p[Y] / cell) * cell);



    if ( (dy / sin(g->angle)) > (dx / cos(g->angle)) )
    {
        p[X] += dx;
        p[Y] += (dx / cos(g->angle)) * sin(g->angle);
        g->side = VL;
    }
    else
    {
        p[X] += (dy / sin(g->angle)) * cos(g->angle);
        p[Y] += dy;
        g->side = HL;
    }


    if      (p[X] < 0)         p[X] = 0;
    else if (p[X] >= cell * 8) p[X] = cell * 8 - 1;
    
    if      (p[Y] < 0)         p[Y] = 0;
    else if (p[Y] >= cell * 8) p[Y] = cell * 8 - 1;

    draw_line(
        (int []){g->xpos, g->ypos}, 
        (int []){p[X], p[Y]}, 
        RED, g);
}

/*
void raycast(t_game *g)
{
    int old[2];
    int new[2];

    old[X] = g->xpos;
    old[Y] = g->ypos;


    if (g->angle >= PI)
        new[Y] = (int)(old[Y]/g->grid) * g->grid;
    else
        new[Y] = ((int)(old[Y]/g->grid) * g->grid + g->grid);


    check_wall(new, g);

    while(true)
    {  
        new[X] = (new[Y] - old[Y]) / tan(g->angle) + old[X];

        if (new[X] < 0) new[X] = 0;
        else if (new[X] > 8 * g->grid) new[X] = 8 * g->grid;

        if (new[Y] < 0) new[Y] = 0;
        else if (new[Y] > 8 * g->grid) new[Y] = 8 * g->grid;

        if (check_wall(new, g))
            break;
        
        old[X] = new[X];
        old[Y] = new[Y];

        if (g->angle >= PI)
            new[Y] = old[Y] - g->grid;
        else
            new[Y] = old[Y] + g->grid;
    }

    draw_line((int []){g->xpos, g->ypos}, new, RED, g);


}
*/