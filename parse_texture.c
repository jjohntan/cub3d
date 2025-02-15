/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:13:24 by jetan             #+#    #+#             */
/*   Updated: 2025/02/15 22:41:38 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	valid_color(int *color)
{
	int	i;
	
	if (!color)
		return ;
	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
		{
			ft_putstr_fd("Error\nInvalid color range", 2);
			exit(1);
		}
		i++;
	}
}

/**
 * @brief This function convert rgb from decimal to hexadecimal
 */
int	color(int r, int g, int b)
{
	return (r << 16) | (g << 8) | (b);
}

void	parse_color(char *line, t_game *data)
{
	char	*trimmed_line;
	char	*path;
	char	**color_value;
	int	rgb[3];
	
	trimmed_line = line;
	line += 1;
	path = ft_strtrim(line, " \t\n");
	color_value = ft_split(path, ',');
	rgb[0] = ft_atoi(color_value[0]);
	rgb[1] = ft_atoi(color_value[1]);
	rgb[2] = ft_atoi(color_value[2]);
	valid_color(rgb);
	if (ft_strncmp(trimmed_line, "F", 1) == 0)
	{
		data->floor = color(rgb[0], rgb[1], rgb[2]);
		printf("floor: %d\n", data->floor);
	}
	else if (ft_strncmp(trimmed_line, "C", 1) == 0)
	{
		data->ceiling = color(rgb[0], rgb[1], rgb[2]);
		printf("ceiling: %d\n", data->ceiling);
	}
}

/**
 * @brief This function store texture path into struct follow by indentifier
 */
void	parse_texture(char *line, t_game *data)
{
	char *trimmed_line;
	char *path;
	
	trimmed_line = line;
	line += 2;
	path = ft_strtrim(line, " \t\n");
	if (ft_strncmp(trimmed_line, "NO", 2) == 0)
	{
		data->texture->no = path;
		printf("NO:%s\n", data->texture->no);
	}
	else if (ft_strncmp(trimmed_line, "SO", 2) == 0)
	{
		data->texture->so = path;
		printf("SO:%s\n", data->texture->so);
	}
	else if (ft_strncmp(trimmed_line, "WE", 2) == 0)
	{
		data->texture->we = path;
		printf("WE:%s\n", data->texture->we);
	}
	else if (ft_strncmp(trimmed_line, "EA", 2) == 0)
	{
		data->texture->ea = path;
		printf("EA:%s\n", data->texture->ea);
	}
}
