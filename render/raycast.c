/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:22 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/24 15:34:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_wall(float p[2], float a, t_game *g)
{
    int x;
    int y;

    x = p[X] / CELL;
    y = p[Y] / CELL;
    if (g->which_cal == Y_INTER && sin(a) < 0)
        y--;
    else if (g->which_cal == X_INTER && cos(a) < 0)
        x--;
    if (g->map[y][x] == '1')
        return (true);
    return (false);
}

void each_ray(float *p, float a, t_game *g)
{
    float ystep[2];
    float xstep[2];

    while (true)
    {
        if (y_only(a) && y_intercept(p, ystep, a))
            g->which_cal = update_point(p, ystep, Y_INTER);
        else if (x_only(a) && x_intercept(p, xstep, a))
            g->which_cal = update_point(p, xstep, X_INTER);
        else
        {
            if (x_intercept(p, xstep, a) > y_intercept(p, ystep, a))
                g->which_cal = update_point(p, ystep, Y_INTER);
            else
                g->which_cal = update_point(p, xstep, X_INTER);
        }
        if (check_wall(p, a, g))
            break;
    }
}

void raycast(t_game *g)
{
    float p[2];
    float i = angle(g->angle - FOV / 2);
    int counter = -1;

    while (++counter < SCREEN)
    {
        p[X] = g->pos[X];
        p[Y] = g->pos[Y];
        each_ray(p, i, g);
        draw_line(
            (int []){g->pos[X], g->pos[Y]},
            (int []){p[X], p[Y]},
            RED, g);
        cal_wall(counter, i, p, g);
        i = angle(i + ANGLE_STEP);
    }
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