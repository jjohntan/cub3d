/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:13:24 by jetan             #+#    #+#             */
/*   Updated: 2025/02/26 15:36:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

bool	parse_path(char *identify, char *path, t_game *data)
{
	if (ft_strncmp(identify, "NO", 2) == 0)
	{
		if (data->no)
			return (false);
		data->no = path;
	}
	else if (ft_strncmp(identify, "SO", 2) == 0)
	{
		if (data->so)
			return (false);
		data->so = path;
	}
	else if (ft_strncmp(identify, "WE", 2) == 0)
	{
		if (data->we)
			return (false);
		data->we = path;
	}
	else if (ft_strncmp(identify, "EA", 2) == 0)
	{
		if (data->ea)
			return (false);
		data->ea = path;
	}
	return (true);
}

/**
 * @brief This function store texture path into struct follow by indentifier
 */
bool	parse_texture(char *line, t_game *data)
{
	char	*identify;
	char	*path;

	identify = line;
	path = ft_strtrim(line + 2, " \t\n");
	if (!parse_path(identify, path, data))
		return (free(line), free(path), false);
	return (true);
}
