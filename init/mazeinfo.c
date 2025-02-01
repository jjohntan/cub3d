/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maze_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:11:01 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/31 13:11:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
void init_player(char c, int x, int y, t_game *g);

//----------------------------------------------------------------------------

void get_maze_info(t_game *g)
{
    int i;
    char c;

    while (g->maze.arr[g->maze.y])
    {
        i = -1;
        while (g->maze.arr[g->maze.y][++i])
        {
            c = g->maze.arr[g->maze.y][i];
            if (!g->p1.x && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
                init_player(c, i, g->maze.y, g);
        }
        if (i > g->maze.x)
            g->maze.x = i;
        g->maze.y++;
    }
}

void init_player(char c, int x, int y, t_game *g)
{
    if (c == 'N')
        g->p1.angle = DEG_270;
    else if (c == 'S')
        g->p1.angle = DEG_90;
    else if (c == 'E')
        g->p1.angle = 0;
    else if (c == 'W')
        g->p1.angle = DEG_180;

    g->p1.x = x * TILE + (TILE / 2);
    g->p1.y = y * TILE + (TILE / 2);
    g->p1.dx = cos(g->p1.angle);
    g->p1.dy = sin(g->p1.angle);
}
