/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/12 21:05:27 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	parse_map(char *line, t_game *data)
{
	while ()
	{
		
	}
}

int	is_map(char *line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

static void	identifier(char *line, t_game *data)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_texture(line, data);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_texture(line, data);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_texture(line, data);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_texture(line, data);
	else if (line[0] == 'F')
		parse_color(line, data);
	else if (line[0] == 'C')
		parse_color(line, data);
	else if (is_map(line))
		// printf("hello");
		parse_map(line, data);
}

int	parser(char *file, t_game *data)
{
	int		fd;
	char	*line;
	// char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo such file", 2);
		return (0);
	}
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		identifier(line, data);
		printf("%s", line);//hello
		free(line);
	}
	close(fd);
	return (1);
}
