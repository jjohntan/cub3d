/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/02/18 22:13:53 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>


// int	check_path(char *path)
// {
// 	int	fd;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	close(fd);
// 	int	len;
// 	len = ft_strlen(path) - 4;
// 	if (ft_strncmp(&path[len], ".xpm", 4) != 0)
// 		return (0);
// 	return (1);
// }

// void	valid_texture(t_game *data)
// {
// 	if ((check_path(data->texture->no) == 0) || (check_path(data->texture->so) == 0) ||
// 	(check_path(data->texture->we) == 0) || (check_path(data->texture->ea) == 0))
// 	{
// 		ft_putstr_fd("Error\nInvalid path", 2);
// 		exit(1);
// 	}
// }

void	count_players(t_game *data)
{
	int	y;
	int	x;
	
	y = 0;
	while (data->map.arr[y])
	{
		x = 0;
		while (data->map.arr[y][x])
		{
			if (ft_strchr("NSEW", data->map.arr[y][x]))
			{
				data->p1.player_count++;
				data->p1.y = y;
				data->p1.x = x;
				data->p1.angle = data->map.arr[y][x];
				printf("player count: %d\n", data->p1.player_count);
				printf("player y: %f\n", data->p1.y);
				printf("player x: %f\n", data->p1.x);
				printf("player angle: %f\n", data->p1.angle);
			}
			x++;
		}
		y++;
	}
}

static void	check_extension(char *av)
{
	int	len;
	
	len = ft_strlen(av) - 4;
	if (len < 4 || ft_strncmp(&av[len], ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\n invalid extension", 2);
		exit(1);
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
	valid_texture(&data);
	valid_map(&data);
	// i = 0;
	printf("\n");
	while (data.map.arr && data.map.arr[i])
	{
		printf("%s", data.map.arr[i]);
		i++;
	}
}
