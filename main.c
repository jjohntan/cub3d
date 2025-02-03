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



int	parse_map(char *file)
{
	int		fd;
	char	*line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
	}
	close(fd);
	return (1);
}

int main(int ac, char **av)
{
	// t_data	data;
	(void)ac;
	(void)av;
	
	 char row0[] = "111111";
    char row1[] = "100101";
    char row2[] = "101001";
    char row3[] = "1100N1";
    char row4[] = "111111";
    char *map[] = { row0, row1, row2, row3, row4, NULL };
	// int i = 0;
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	// ft_bzero(&data, sizeof(t_data);
	// check_extension(av[1]);
	// check_walls(map);
	// check_char(map);
	parse_map(map);
	// flood_fill(map, 4, 3);
	// valid_map(map);
	// i = 0;
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
}
