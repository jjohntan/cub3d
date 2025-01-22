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

int check_wall(int new[2], t_game *g)
{
    int x;
    int y;

    x = (int)(new[X] / g->grid);
    y = (int)(new[Y] / g->grid);

    if (g->angle >= PI)
        y--;
    if (g->map[y][x] == '1')
        return (true);
    return (false);
}

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
