/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:51:15 by jetan             #+#    #+#             */
/*   Updated: 2025/02/24 16:41:31 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

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
	if ((check_path(data->no) == 0) || (check_path(data->so) == 0) ||
	(check_path(data->we) == 0) || (check_path(data->ea) == 0))
		error_exit("Error\nInvalid path\n");
}