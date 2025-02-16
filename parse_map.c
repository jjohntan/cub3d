/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/13 16:56:42jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	count_line(char *file)
// {
// 	int	fd;
// 	int	count;
// 	char	*line;
	
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	count = 0;
// 	while (line = get_next_line(fd))
// 	{
// 		count++;
// 		free(line);
// 	}
// 	return (count);
// }

void	parse_map(char *line, t_game *data)
{
	int	i;
	
	i = 0;
	data->map.arr[i] = ft_strdup(line);
		i++;
	data->map.height++;
}

int	is_map(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' &&
		 line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != 'D' && line[i] != ' ')
		 {
			printf("hello");
			exit(1);
		 }
		i++;
	}
	return (1);
}

char	*skip_space(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] == ' ' || line [i] == '\t')
		i++;
	return (&line[i]);
}

static void	identifier(char *line, t_game *data)
{
	char	*skip;
	
	skip = skip_space(line);
	if ((skip[0] == 'N' && skip[1] == 'O') ||
	 (skip[0] == 'S' && skip[1] == 'O') ||
	 (skip[0] == 'W' && skip[1] == 'E') ||
	 (skip[0] == 'E' && skip[1] == 'A'))
		parse_texture(skip, data);
	else if ((skip[0] == 'F') ||
	 (skip[0] == 'C'))
		parse_color(skip, data);
	else if (is_map(skip))//
		printf("hi\n");
		// parse_map(line, data);
}


int	parser(char *file, t_game *data)
{
	int		fd;
	char	*line;

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
