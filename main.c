/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/02/21 15:21:56 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	check_file_extension(char *av)
{
	int	len;
	
	len = ft_strlen(av) - 4;
	if (len < 4 || ft_strncmp(&av[len], ".cub", 4) != 0)
		error_exit("Error\nInvalid extension");
}

int main(int ac, char **av)
{
	t_game	data;
	
	if (ac != 2)
		error_exit("Error\nInvalid number of argument");
	ft_bzero(&data, sizeof(t_game));
	check_file_extension(av[1]);
	parser(av[1], &data);
	valid_texture(&data);
	valid_map(&data);
	// int i = 0;
	// printf("\n");
	// while (data.map.arr && data.map.arr[i])
	// {
	// 	printf("%s", data.map.arr[i]);
	// 	i++;
	// }
}
