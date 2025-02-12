/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:29:29 by jetan             #+#    #+#             */
/*   Updated: 2025/02/12 19:55:52 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color(int r, int g, int b)
{
	return (r << 16) | (g << 8) | (b);
}

void	parse_color(char *line, t_game *data)
{
	char	**split;
	int	r;
	int	g;
	int	b;
	
	split = ft_split(line + 1, ',');
	if (split[0] && split[1] && split[2] && !split[3])
	{
		r = ft_atol(split[0]); // "300" "    -23123abcc++"  "abc"
		g = ft_atol(split[1]);
		b = ft_atol(split[2]);
		if (line[0] == 'F')
		{                        // 0 - 255   
			data->floor = color(r, g, b); // rgb value already correct
			printf("floor: %d\n", data->floor);
		}
		else if (line[0] == 'C')
		{
			data->ceiling = color(r, g, b);
			printf("ceiling: %d\n", data->ceiling);
		}
	}
	free(split);//bug
}

void	assign_path(char **split, char *path, t_game *data)
{	
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
	free(split);
}

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
		assign_path(split, path, data);
	}
}
