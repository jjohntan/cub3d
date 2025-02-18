/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/02/18 21:55:05by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void	check_walls(char **map)
// {
// 	int	i;
// 	int	j;
	
// 	int h = 5;
// 	int w = 6;
// 	i = 0;
// 	while (i < h)
// 	{
// 		j = 0;
// 		while (j < w)
// 		{
// 			if (i == 0 || i == h - 1 ||
// 			j == 0 || j == w - 1)
// 			{
// 				if (map[i][j] != '1' || map[i][j] != ' ')
// 				{
// 					ft_putstr_fd("Error\nmap must be closed by walls a", 2);
// 					return ;
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

/**
 * @brief This function check that the map closed/surrounded by walls
 */
void	flood_fill(t_game *data, int x, int y)
{
	char	**map;
	
	map = data->map.tmp_arr;
	printf("Visiting (y: %d, x: %d): %c\n", y, x, map[y][x]);//hello
	if (x < 0 || x >= data->map.width || y < 0 || y >= data->map.height)
		return ;
	if  (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (x == 0 || x == data->map.width - 1 || y == 0 || y == data->map.height - 1)
	{
		if (map[y][x] != '1')
		{
			ft_putstr_fd("Error\nThe map must be closed/surrounded by walls", 2);
			exit(1);
		}
	}
	map[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

void	check_player(t_game *data)
{
	
	count_players(data);
	if (data->p1.player_count == 0)
	{
		ft_putstr_fd("Error\nNo player starting position found", 2);
		exit(1);
	}
	if (data->p1.player_count > 1)
	{
		ft_putstr_fd("Error\nMutiple player starting position found", 2);
		exit(1);
	}
}

void	check_char(char **map)
{
	int	h;
	int	w;
	
	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w])
		{
			if (map[h][w] != '0'&& map[h][w] != '1' && map[h][w]!= 'N' &&
			 map[h][w]!= 'S' && map[h][w]!='E' && map[h][w]!= 'W' &&
			  map[h][w] != 'D' && map[h][w] != ' ')
			{
				ft_putstr_fd("Error\nInvalid character in map", 2);
				exit(1);
			}
			w++;
		}
		h++;
	}
}

void	valid_map(t_game *data)
{

	check_char(data->map.arr);
	check_player(data);
	flood_fill(data, data->p1.x, data->p1.y);
}