/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:34 by jetan             #+#    #+#             */
/*   Updated: 2025/02/20 20:57:44 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	int	len;
	len = ft_strlen(path) - 4;
	if (ft_strncmp(&path[len], ".xpm", 4) != 0)
		return (0);
	return (1);
}

void	valid_texture(t_game *data)
{
	if ((check_path(data->texture->no) == 0) || (check_path(data->texture->so) == 0) ||
	(check_path(data->texture->we) == 0) || (check_path(data->texture->ea) == 0))
	{
		ft_putstr_fd("Error\nInvalid path", 2);
		exit(1);
	}
}

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
	(void)ac;
	
	ft_bzero(&data, sizeof(t_game));
	check_file_extension(av[1]);
	parser(av[1], &data);
	// valid_texture(&data);
	valid_map(&data);
	// int i = 0;
	// printf("\n");
	// while (data.map.arr && data.map.arr[i])
	// {
	// 	printf("%s", data.map.arr[i]);
	// 	i++;
	// }
}
