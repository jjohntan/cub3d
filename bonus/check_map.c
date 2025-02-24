/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/02/24 16:51:31 by jetan            ###   ########.fr       */
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
	// printf("x:%d y:%d w:%d h:%d\n", x, y, data->map.w, data->map.h);//hello
	if (x < 0 || x >= data->map.w || y < 0 || y >= data->map.h)
		return ;
	// printf("Visiting (%d, %d): %c\n", x, y, map[y][x]);//
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (x == 0 || x == data->map.w - 1 || y == 0
		|| y == data->map.h - 1)
	{
		if (map[y][x] != '1')
			error_exit("Error\nThe map must be closed/surrounded by walls");
	}
	map[y][x] = 'F';
	int i = 0;
	while (data->map.tmp[i])
	{
		printf("%s", data->map.tmp[i]);
		i++;
	}
	printf("\n\n");
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}

/**
 * @brief This function check that is only one player starting position.
 */
void	check_player(t_game *data)
{
	count_players(data);
	if (data->p1.player_count == 0)
		error_exit("Error\nNo player starting position found");
	if (data->p1.player_count > 1)
		error_exit("Error\nMutiple player starting position found");
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
			if (map[row][col] != '0' && map[row][col] != '1' && map[row][col] != 'N'
			&& map[row][col] != 'S' && map[row][col] != 'E' && map[row][col] != 'W'
			&& map[row][col] != 'D' && map[row][col] != ' ' && map[row][col] != '\n')
				error_exit("Error\nInvalid character in map");
			col++;
		}
		row++;
	}
}

char **dup_map(t_game *data)
{
    int i;
    char **new_map;

    i = -1;
    new_map = (char **)malloc((data->map.h + 1) * sizeof(char *));//h
    while (data->map.ar[++i])
        new_map[i] = ft_strdup(data->map.ar[i]);
    new_map[i] = NULL;
    return (new_map);
}

/**
 * @brief This function validate the specified map that parsed in
 */
void	valid_map(t_game *data)
{
	data->map.tmp = dup_map(data);
	check_char(data->map.ar);
	check_player(data);
	flood_fill(data, data->p1.x, data->p1.y);
	// int i = 0;
	// while (data->map.tmp_arr[i])
	// {
	// 	printf("%s", data->map.tmp_arr[i]);
	// 	i++;
	// }
}
