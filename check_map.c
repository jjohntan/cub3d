/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/02/12 21:05:47 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (map[h][w] != '0'&& map[h][w] != '1' && map[h][w]!= 'N' && map[h][w]!= 'S' && map[h][w]!='E' && map[h][w]!= 'W' && map[h][w] != 'D')
			{
				ft_putstr_fd("Error\nInvalid character in map", 2);
				return ;
			}
			w++;
		}
		h++;
	}
}

void	check_walls(char **map)
{
	int	i;
	int	j;
	
	int h = 5;
	int w = 6;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (i == 0 || i == h - 1 ||
			j == 0 || j == w - 1)
			{
				if (map[i][j] != '1' || map[i][j] != ' ')
				{
					ft_putstr_fd("Error\nmap must be closed by walls a", 2);
					return ;
				}
			}
			j++;
		}
		i++;
	}
}



/**
 * if reach a boundary, map is not closed
 */
void	flood_fill(char **map, int x, int y)//bug
{
	int w = 11, h = 5;

	printf("Visiting (y: %d, x: %d): %c\n", y, x, map[y][x]);//hello
	if (x < 0 || x >= w || y < 0 || y >= h)
		return ;
	if  (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (x == 0 || x == w - 1 || y == 0 || y == h - 1)
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

// static void	free_map(char **map, int height)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < height)
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }

void	valid_map(char **map)
{
	char	**tmp_map;
	int	i;
	
	int h = 5;
	tmp_map = malloc(sizeof(char *) * h);
	if (!tmp_map)
		return ;
	i = 0;
	while (i < h)
	{
		tmp_map[i] = ft_strdup(map[i]);
		i++;
	}
	tmp_map[i] = '\0';
	flood_fill(tmp_map, 4, 3);
	// free_map(tmp_map, h);
	// i = 0;
	// while (tmp_map[i])
	// {
	// 	printf("%s\n", tmp_map[i]);
	// 	i++;
	// }
}
