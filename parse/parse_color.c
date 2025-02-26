/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:13:47 by jetan             #+#    #+#             */
/*   Updated: 2025/02/26 15:37:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/**
 * @brief This function convert rgb from decimal to hexadecimal
 */
int	color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

/**
 * @brief This function split color value into 2d array
 */
void	parse_rgb(char *path, int *value, t_game *data)
{
	int		rgb[3];
	char	**split;

	check_color_format(path, data);
	split = ft_split(path, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		free_map(split);
		error_exit("Color: Missing / incomplete data", data);
	}	
	rgb[0] = ft_atoi(split[0]);
	rgb[1] = ft_atoi(split[1]);
	rgb[2] = ft_atoi(split[2]);
	if (!color_range(rgb))
		error_exit("Color: Invalid range", data);
	*value = color(rgb[0], rgb[1], rgb[2]);
	free_map(split);
}

/**
 * @brief identify: identifier
 * 
 * This function parse color into struct
 */
bool	parse_color(char *line, t_game *data)
{
	char	*identify;
	char	*path;

	identify = line;
	path = ft_strtrim(line + 1, " \t\n");
	if (ft_strncmp(identify, "F", 1) == 0)
	{
		if (data->f)
			return (free(line), free(path), false);
		data->f = path;
	}
	else if (ft_strncmp(identify, "C", 1) == 0)
	{
		if (data->c)
			return (free(line), free(path), false);
		data->c = path;
	}
	return (true);
}
