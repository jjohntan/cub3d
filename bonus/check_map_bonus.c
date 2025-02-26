/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/02/26 15:22:59 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/**
 * @brief This function check that the map closed/surrounded by walls
 */
void	flood_fill(t_game *data, int x, int y)
{
	char	**map;

	map = data->map.tmp;
	if (x < 0 || x >= data->map.w || y < 0 || y >= data->map.h)
		error_exit("Map: Must be closed/surrounded by walls", data);
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

/**
 * @brief This function check that is only one player starting position.
 */
void	check_player(t_game *data)
{
	count_players(data);
	if (data->p1.player_count == 0)
		error_exit("Map: No player starting position found", data);
	if (data->p1.player_count > 1)
		error_exit("Map: Mutiple player starting position found", data);
}

/**
 * @brief This function check the element in the map.
 */
void	check_char(char **map, t_game *data)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] != '0' && map[row][col] != '1'
			&& map[row][col] != 'N' && map[row][col] != 'S'
			&& map[row][col] != 'E' && map[row][col] != 'W'
			&& map[row][col] != ' ' && map[row][col] != 'D')
				error_exit("Map: Invalid character found", data);
			col++;
		}
		row++;
	}
}

/**
 * @brief This function duplicate a temporary map for flood fill
 */
static char	**dup_map(t_game *data)
{
	int		i;
	char	**new_map;

	i = -1;
	new_map = (char **)malloc(sizeof(char *) * (data->map.h + 1));
	while (data->map.ar[++i])
	{
		new_map[i] = (char *)ft_calloc(data->map.w + 1, 1);
		ft_strcpy(new_map[i], data->map.ar[i]);
	}
	new_map[i] = NULL;
	return (new_map);
}

/**
 * @brief This function validate the specified map that parsed in
 */
void	valid_map(t_game *data)
{
	int	x;
	int	y;

	if (!data->map.ar)
		error_exit("Map: No data", data);
	data->map.tmp = dup_map(data);
	check_char(data->map.ar, data);
	check_player(data);
	x = (int)data->p1.x / TILE;
	y = (int)data->p1.y / TILE;
	flood_fill(data, x, y);
	free_map(data->map.tmp);
	data->map.tmp = NULL;
}
