/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:46:33 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/30 09:46:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static void copy_maze_section(int x, int y, t_game *g);

//----------------------------------------------------------------------------

void draw_minimap(t_game *g)
{
    int a[2];
    int b[2];
    int center;
    int r;

    r = 20;
    center = MINI_W / 2;
    copy_maze_section(g->p1.x / S, g->p1.y / S, g);
    a[X] = center + r * cos(angle_limit(g->p1.angle - PI / 9));
    a[Y] = center + r * sin(angle_limit(g->p1.angle - PI / 9));
    b[X] = center + r * cos(angle_limit(g->p1.angle + PI / 9));
    b[Y] = center + r * sin(angle_limit(g->p1.angle + PI / 9));
    
    draw_triangle(
        (int []){center, a[X], b[X]},
        (int []){center, a[Y], b[Y]},
        P1_FOV, g);

    draw_circle(
        (int []){center, center}, 
        3, P1_POS, g);
}

static void copy_maze_section(int x, int y, t_game *g)
{
    int i;
    int j;
    int xmin;
    int color;

    j = -1;
    y -= MINI_W / 2;
    xmin = x - (MINI_W / 2);
    while (++j < MINI_W)
    {
        i = -1;
        x = xmin;
        while (++i < MINI_W)
        {
            if (x >= 0 && x < g->mini.w && y >= 0 && y < g->mini.h)
            {
                color = g->mini.buf[y * g->mini.w + x];
                putpx_disp(i, j, color, g);
            }
            else
                putpx_disp(i, j, VOID, g);
            x++;
        }
        y++;
    }
}
