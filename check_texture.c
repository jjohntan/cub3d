/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:51:15 by jetan             #+#    #+#             */
/*   Updated: 2025/02/21 15:25:24 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		error_exit("Error\nInvalid path");
}