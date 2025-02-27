/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/26 17:35:59 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

int	parse_map(char *line, t_game *data)
{
	char	**tmp;
	int		i;

	if (!line)
		exit (1);
	tmp = (char **)malloc(sizeof(char *) * (++data->map.h + 1));
	if (!tmp)
		exit(1);
	i = 0;
	while (data->map.ar && data->map.ar[i])
	{
		tmp[i] = data->map.ar[i];
		i++;
	}
	tmp[i++] = line;
	tmp[i] = NULL;
	if (data->map.ar)
		free(data->map.ar);
	data->map.ar = tmp;
	get_map_width(data);
	return (1);
}

bool	is_identifier(char *skip)
{
	return ((skip[0] == 'N' && skip[1] == 'O')
		|| (skip[0] == 'S' && skip[1] == 'O')
		|| (skip[0] == 'W' && skip[1] == 'E')
		|| (skip[0] == 'E' && skip[1] == 'A'));
}

/**
 * @param line: The line to be processed. 
 * @param data: data struct.
 * @param counter: tracks the number of processed identifiers.
 * @brief
 * This function skips leading spaces in the given line and checks if the line
 * is blank. If the line contains texture or color identifiers,
 * it calls the appropriate parsing function and increments the counter.
 */
static int	identifier(char *line, t_game *data, int *counter, int fd)
{
	char	*skip;

	skip = skip_space(line);
	if (!skip[0])
		return (1);
	if (is_identifier(skip))
	{
		if (!parse_texture(skip, data))
		{
			flush_gnl(fd);
			error_exit("Texture: Duplicate data", data);
		}
		return ((*counter)++, 1);
	}
	else if ((skip[0] == 'F') || (skip[0] == 'C'))
	{
		if (!parse_color(skip, data))
		{
			flush_gnl(fd);
			error_exit("Color: Duplicate data", data);
		}
		return ((*counter)++, 1);
	}
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("No such file", NULL);
	return (fd);
}

/**
 * @brief Parses the given file and store into the struct.
 *
 * This function opens the specified file, reads its contents line by line.
 * The first six lines are expected to contain identifiers, which are processed
 * and stored in the struct. After the identifiers, the function processes
 * the map data.
 *true : is an element  >> extract >> increment counter (max 6)
 *false: not an element >> err_msg
 *true : blank >> but no increment 
 * @param file The path to the file to be parsed.
 */
void	parser(char *file, t_game *data)
{
	char	*line;
	int		fd;
	int		counter;

	fd = open_file(file);
	counter = 0;
	while (read_line(fd, &line))
	{
		if (counter < 6)
		{	
			if (!identifier(line, data, &counter, fd))
			{
				free(line);
				flush_gnl(fd);
				error_exit("First 6 datas must be game elements", data);
			}
			free(line);
		}
		else if (counter == 6 && blankstr(line))
			free(line);
		else
			counter += parse_map(line, data);
	}
	close(fd);
}
