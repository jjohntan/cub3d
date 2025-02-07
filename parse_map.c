/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/07 14:59:32 by jetan            ###   ########.fr       */
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

void	parse_texture(char *line)
{
	int	i;
	
	i = 2;
}

void	identifier(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_texture(line);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_texture(line);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_texture(line);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_texture(line);
	else if (line[0] == 'F')
		parse_color(line);
	else if (line[0] == 'C')
		parse_color(line);
}

char	**parse_map(char *file)
{
	int		fd;
	char	*line;
	char    **map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo such file", 2);
		return (0);
	}
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		
		// if (line[0] == '\n')
		// {
		// 	free(line);
		// 	continue;
		// }
		identifier(line);
		printf("%s", line);//hello
		free(line);
	}
	close(fd);
	return (map);
}
