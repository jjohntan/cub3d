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

static char	**dup_map(t_game *g);
static bool	flood(char **map, int x, int y, int size[2]);

/*
map_leak
=============================================================================
Using flood fill algo to determine if map not surrounded with walls
*/

bool	map_leak(t_game *g)
{
	int		x;
	int		y;
	char	**map;

	x = (int)g->p1.x / TILE;
	y = (int)g->p1.y / TILE;
	map = dup_map(g);
	if (flood(map, x, y, (int []){g->map.x, g->map.y}))
		return (free_map(map), true);
	free_map(map);
	return (false);
}

static bool	flood(char **map, int x, int y, int size[2])
{
	if (x < 0 || x >= size[X] || y < 0 || y >= size[Y])
		return (true);
	if (map[y][x] == '1')
		return (false);
	map[y][x] = '1';
	if (flood(map, x + 1, y, size)
		|| flood(map, x - 1, y, size)
		|| flood(map, x, y + 1, size)
		|| flood(map, x, y - 1, size))
		return (true);
	return (false);
}

/*
Note: 
- allocated str size == map.x 
- This is to make all string same length (avoid overflow)
*/

static char	**dup_map(t_game *g)
{
	int		i;
	char	**new_map;

	i = -1;
	new_map = (char **)malloc(sizeof(char *) * (g->map.y + 1));
	while (g->map.ar[++i])
	{
		new_map[i] = (char *)ft_calloc(g->map.x + 1, 1);
		ft_strcpy(new_map[i], g->map.ar[i]);
	}
	new_map[i] = NULL;
	return (new_map);
}
