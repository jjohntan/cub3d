/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:03:00 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/29 22:03:00 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static void put_tile(int x, int y, int color, t_game *g);

//----------------------------------------------------------------------------

void init_minimap(t_game *g)
{
    t_img i;
        
    g->mini.h = g->maze.y * MINI_T;
    g->mini.w = g->maze.x * MINI_T;
    g->mini.ptr = mlx_new_image(g->mlx, g->mini.w, g->mini.h);
    g->mini.buf = (int *)mlx_get_data_addr(g->mini.ptr, &i.bpp, &i.row, &i.end);
    update_mini_img(g);
}

void update_mini_img(t_game *g)
{
    int x;
    int y;
    char c;

    y = -1;
    while (g->maze.arr[++y])
    {
        x = -1;
        while(g->maze.arr[y][++x])
        {
            c = g->maze.arr[y][x];
            if (c == '1')
                put_tile(x, y, WALL, g);
            else if (c == 'D')
                put_tile(x, y, DOOR, g);
            else if (c != ' ')
                put_tile(x, y, SPACE, g);
        }
    }
}

static void put_tile(int x, int y, int color, t_game *g)
{
    int i; 
    int j;

    y *= MINI_T;
    x *= MINI_T;
    j = y - 1;
    while (++j < y + MINI_T)
    {
        i = x - 1;
        while (++i < x + MINI_T)
            putpx_img(i, j, color, g);  
    }
}
