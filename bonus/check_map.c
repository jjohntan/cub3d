/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/02/25 21:59:08 by jetan            ###   ########.fr       */
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
		error_exit("Error\nThe map must be closed/surrounded by walls\n");
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
		error_exit("Error\nNo player starting position found\n");
	if (data->p1.player_count > 1)
		error_exit("Error\nMutiple player starting position found\n");
}

/**
 * @brief This function check the element in the map.
 */
void	check_char(char **map)
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
			&& map[row][col] != 'D' && map[row][col] != ' ')
				error_exit("Error\nInvalid character in map\n");
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
		error_exit("Error\nNo map data found\n");
	data->map.tmp = dup_map(data);
	check_char(data->map.ar);
	check_player(data);
	x = (int)data->p1.x / TILE;
	y = (int)data->p1.y / TILE;
	flood_fill(data, x, y);
	free_map(data->map.tmp);
}
