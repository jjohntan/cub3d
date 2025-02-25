/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:13:47 by jetan             #+#    #+#             */
/*   Updated: 2025/02/24 22:22:45 by jetan            ###   ########.fr       */
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

void	parse_rgb(char *path, int *value)
{
	int	rgb[3];
	char **color_value;
	
	check_color_format(path);
	color_value = ft_split(path, ',');
	rgb[0] = ft_atoi(color_value[0]);
	rgb[1] = ft_atoi(color_value[1]);
	rgb[2] = ft_atoi(color_value[2]);
	color_range(rgb);
	*value = color(rgb[0], rgb[1], rgb[2]);
	free(color_value[0]);
	free(color_value[1]);
	free(color_value[2]);
}

/**
 * @brief identify: identifier
 * 
 * This function parse color into struct
 */
void	parse_color(char *line, t_game *data)
{
	char	*identify;
	char	*path;

	identify = line;
	path = ft_strtrim(line + 1, " \t\n");
	if (ft_strncmp(identify, "F", 1) == 0)
	{
		if (data->f)
			error_exit("Error\nDuplicate color\n");
		data->f = path;
	}
	else if (ft_strncmp(identify, "C", 1) == 0)
	{
		if (data->c)
			error_exit("Error\nDuplicate color\n");
		data->c = path;
	}
}
