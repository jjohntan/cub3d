/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/02/03 15:14:41 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 
 */
void	flood_fill(char **map, int x, int y)
{
	int w = 6, h = 5;

	printf("Visiting (y: %d, x: %d): %c\n", y, x, map[y][x]);
	if (x < 0 || x >= w || y < 0 || y >= h)
		return ;
	if  (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (x == 0 || x == w - 1 || y == 0 || y == h - 1)
	{
		if (map[y][x] != '1')
		{
			ft_putstr_fd("Error\nThe map must be closed/surrounded by walls", 2);
			exit(1) ;
		}
	}
	map[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
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
			if (map[h][w] != '0'&& map[h][w] != '1' && map[h][w]!= 'N' && map[h][w]!= 'S' && map[h][w]!='E' && map[h][w]!= 'W')
			{
				ft_putstr_fd("Error\nInvalid character in map", 2);
				return ;
			}
			w++;
		}
		h++;
	}
}
