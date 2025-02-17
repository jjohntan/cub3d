/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/02/17 22:46:09 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	check_extension(char *av)
{
	int	len;
	
	len = ft_strlen(av) - 4;
	if (len < 4 || ft_strncmp(&av[len], ".cub", 4) != 0)
		ft_putstr_fd("Error\n invalid extension", 2);
}

void	valid_texture(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return ;
	}
	close(fd);
	int	len;
	len = ft_strlen(file) - 4;
	if (ft_strncmp(&file[len], ".xpm", 4) != 0)
		printf("hello");
}

int	count_players(char **map)
{
	int	y;
	int	x;
	int	player_count;
	
	player_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				player_count++;
				// ->y = y;
				// ->x = x;
				// ->angle = map[y][x];
			}
			x++;
		}
		y++;
	}
	return (player_count);
}

void	valid_player(char **map)
{
	char	player_count;
	
	player_count = count_players(map);
	if (player_count == 0)
	{
		ft_putstr_fd("Error\nNo player starting position found", 2);
		return ;
	}
	if (player_count > 1)
	{
		ft_putstr_fd("Error\nMutiple player starting position found", 2);
		return;
	}
}

int main(int ac, char **av)
{
	t_game	data;
	(void)ac;
	// (void)av;
	
	
	// char row0[] = "       1    ";
	// char row1[] = "      101   ";
	// char row2[] = "     10001  ";
	// char row3[] = "    100N001 ";
	// char row4[] = "   111111111";
	// char *map[] = { row0, row1, row2, row3, row4, NULL };
	//  char row0[] = "111111";
	//    char row1[] = "100101";
	//    char row2[] = "101001";
	//    char row3[] = "1100N1";
	//    char row4[] = "111111";
	//    char *map[] = { row0, row1, row2, row3, row4, NULL };
	int i = 0;
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// 0}
	ft_bzero(&data, sizeof(t_game));
	check_extension(av[1]);
	parser(av[1], &data);
	// valid_map(map);
	// check_walls(map);
	// check_char(map);
	// flood_fill(map, 5, 3);
	// valid_texture(av[1]);
	// i = 0;
	printf("\n");
	while (data.map.arr && data.map.arr[i])
	{
		printf("%s", data.map.arr[i]);
		i++;
	}
	// valid_player(map);
}
