/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/07 19:29:44 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_char(char **map)
{
	int	h;
	int	w;
	
	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w])
		{
			if (map[h][w] != '0'&& map[h][w] != '1' && map[h][w]!= 'N' && map[h][w]!= 'S' && map[h][w]!='E' && map[h][w]!= 'W' && map[h][w] != 'D')
			{
				ft_putstr_fd("Error\nInvalid character in map", 2);
				return ;
			}
			w++;
		}
		h++;
	}
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
	// else if (line[0] == 'F')
	// 	parse_color(line, data);
	// else if (line[0] == 'C')
	// 	parse_color(line, data);
}

int	parse_map(char *file, t_game *data)
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
