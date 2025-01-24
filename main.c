/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/01/24 15:34:38by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <fcntl.h>



// static int	valid_color(int *color)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (color[i] < 0 || color[i] > 255)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// static void	check_extension(char *av)
// {
// 	int	len;
	
// 	len = ft_strlen(av) - 4;
// 	if (len < 4 || ft_strncmp(&av[len], ".cub", 4) != 0)
// 		ft_putstr_fd("Error\n invalid extension", 2);
// }

/**
 * if reach a boundary, map is not closed
 */
void	flood_fill(char **map, int x, int y)
{
	int w = 6, h = 5;

	if (x < 0 || x >= w || y < 0 || y >= h)
		return ;
	printf("Visiting (%d, %d): %c\n", x, y, map[y][x]);

	if  (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	// if (x == 0 || x == w - 1 || y == 0 || y == h - 1)
	// {
	// 	if (map[y][x] != '1')
	// 		return ;
	// }
	map[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

// int	parse_map(const char *file)
// {
// 	int		fd;
// 	char	*line;
	
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	line = NULL;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 	}
// 	close(fd);
// 	return (1);
// }

int main(int ac, char **av)
{
	// t_data	data;
	(void)ac;
	(void)av;
	
	char *map[] = {
		"111111",
		"100101",
		"101001",
		"1100N1",
		"111111",
		NULL
	};
	// ft_bzero(&data, sizeof(t_data);
	// check_extension(av[1]);
	// check_walls(map);
	// check_char(map);
	// parse_map(map);
	// flood_fill(map, 4, 3);
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
