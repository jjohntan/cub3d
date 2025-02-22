/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:29:31 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/21 13:29:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static char **dup_map(t_game *g);
static bool flood(char **map, int x, int y, int xsize, int ysize);

/*
map_leak
=============================================================================
Using flood fill algo to determine if map not surrounded with walls
*/
bool map_leak(t_game *g)
{
    int x;
    int y;
    char **map;
    
    x = (int)g->p1.x / TILE;
    y = (int)g->p1.y / TILE;
    map = dup_map(g);
    if (flood(map, x, y, g->map.x, g->map.y))
        return (free_map(map), true);
    free_map(map);
    return (false);
}


static bool flood(char **map, int x, int y, int xsize, int ysize)
{
    if (x < 0 || x >= xsize || y < 0 || y >= ysize)
        return (true);
    if (map[y][x] == '1')
        return (false);
    map[y][x] = '1';
    if (flood(map, x + 1, y, xsize, ysize)
        || flood(map, x - 1, y, xsize, ysize)
        || flood(map, x, y + 1, xsize, ysize)
        || flood(map, x, y - 1, xsize, ysize))
        return (true);
    return (false);
}

/*
Note: 
- allocated str size == map.x 
- This is to make all string same length (avoid overflow)
*/ 
static char **dup_map(t_game *g)
{
    int i;
    char **new_map;

    i = -1;
    new_map = (char **)malloc(sizeof(char *) * (g->map.y + 1));
    while (g->map.ar[++i])
    {
        new_map[i] = (char *)calloc(g->map.x + 1, 1);
        strcpy(new_map[i], g->map.ar[i]);
    }
    new_map[i] = NULL;
    return (new_map);
}