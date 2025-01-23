/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/01/23 17:05:58 by jetan            ###   ########.fr       */
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

// int	reading_file(file)
// {
// 	int		fd;
// 	char	*line;
	
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	while (line = get_next_line(fd) != NULL)
// 	{
		
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
	// reading_file();
	// check_walls(map);
	check_char(map);
}
