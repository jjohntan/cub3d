/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:13:24 by jetan             #+#    #+#             */
/*   Updated: 2025/02/14 22:47:17 by jetan            ###   ########.fr       */
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
			return ;
		}
		i++;
	}
}

int	color(int r, int g, int b)
{
	return (r << 16) | (g << 8) | (b);
}

void	parse_color(char *line, t_game *data)
{
	char	trimmed_line;
	char	*rgb[3];
	int	i;
	
	trimmed_line = skip_space(line);
	i = 0;
	while (rgb[i])
	{
		= ft_atoi(rgb[i]);
		
	}
	if (ft_strncmp(trimmed_line, "F", 1) == 0)
	{
		data->floor = color();
		printf("floor: %d\n", data->floor);
	}
	else if (ft_strncmp(trimmed_line, "C", 1) == 0)
	{
		data->ceiling = color();
		printf("ceiling: %d\n", data->ceiling);
	}
}

void	parse_texture(char *line, t_game *data)
{
	char *trimmed_line;
	char *path;
	
	trimmed_line = skip_space(line);
	line += 2;
	path = ft_strtrim(line, " \n\t");
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
