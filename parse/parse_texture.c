/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:13:24 by jetan             #+#    #+#             */
/*   Updated: 2025/02/24 22:18:15 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void	parse_path(char *identify, char *path, t_game *data)
{
	if (ft_strncmp(identify, "NO", 2) == 0)
	{
	    if (data->no)
			error_exit("Error\nDuplicate data\n");
		data->no = path;
	}
	else if (ft_strncmp(identify, "SO", 2) == 0)
	{
		if (data->so)
			error_exit("Error\nDuplicate data\n");
		data->so = path;
	}
	else if (ft_strncmp(identify, "WE", 2) == 0)
	{
		if (data->we)
			error_exit("Error\nDuplicate data\n");
		data->we = path;
	}
	else if (ft_strncmp(identify, "EA", 2) == 0)
	{
		if (data->ea)
			error_exit("Error\nDuplicate data\n");
		data->ea = path;
	}
}

/**
 * @brief This function store texture path into struct follow by indentifier
 */
void	parse_texture(char *line, t_game *data)
{
	char	*identify;
	char	*path;

	identify = line;
	path = ft_strtrim(line + 2, " \t\n");
	parse_path(identify, path, data);
}
