/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:29:29 by jetan             #+#    #+#             */
/*   Updated: 2025/02/07 19:41:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_texture(char *line, t_game *data)
{
	char	**split;
	char	*path;

	split = ft_split(line, ' ');
	if (!split)
		return ;
	if (split[0] && split[1] && !split[2])
	{
		path = ft_strtrim(split[1], "\n");
		if (!path)
			return ;
		if (ft_strncmp(split[0], "NO", 2) == 0)
		{
			data->texture->no = path;
			printf("NO: %s\n", data->texture->no);
		}
		else if (ft_strncmp(split[0], "SO", 2) == 0)
		{
			data->texture->so = path;
			printf("SO: %s\n", data->texture->so);
		}
		else if (ft_strncmp(split[0], "WE", 2) == 0)
		{
			data->texture->we = path;
			printf("WE: %s\n", data->texture->we);
		}
		else if (ft_strncmp(split[0], "EA", 2) == 0)
		{
			data->texture->ea = path;
			printf("EA: %s\n", data->texture->ea);
		}
	}
}


