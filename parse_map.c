/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/20 21:00:29y jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	is_map(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (line[i] == '\0' || line[i] == '\n')
// 		return (0);
// 	while (line[i] != '\0' && line[i] != '\n')
// 	{
// 		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' &&
// 		 line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != 'D' && line[i] != ' ')
// 		 {
// 			ft_putstr_fd("Error\nInvalid character in map", 2);
// 			exit(1);
// 		 }
// 		i++;
// 	}
// 	return (1);
// }
/**
 * @brief This function skip empty line
 */
int	blankstr(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

/*
- true : is an element  >> extract >> increment counter (max 6)
- false: not an element >> err_msg
- true : blank >> but no increment 
*/
void	parse_map(char *line, t_game *data)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (++data->map.y + 1));
	if (!tmp)
		exit(1);
	i = 0;
	while (data->map.arr && data->map.arr[i])
	{
		tmp[i] = data->map.arr[i];
		i++;
	}
	tmp[i++] = line;
	tmp[i] = NULL;
	if (data->map.arr)
		free(data->map.arr);
	data->map.arr = tmp;
	data->map.height = data->map.y;
	i = -1;
	while (data->map.arr[++i] != NULL)
	{
		int len = ft_strlen(data->map.arr[i]);
		if (len > data->map.width)
			data->map.width = len;
	}
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
static int	identifier(char *line, t_game *data, int *counter)
{
	char	*skip;
	
	skip = skip_space(line);
	// printf("Check:[%s] [%s]\n", skip, line);//
	if (!skip[0])
		return (1);
	if ((skip[0] == 'N' && skip[1] == 'O') || (skip[0] == 'S' && skip[1] == 'O')
		|| (skip[0] == 'W' && skip[1] == 'E')
		|| (skip[0] == 'E' && skip[1] == 'A'))
	{
		parse_texture(skip, data);
		(*counter)++;
		return (1);
	}
	else if ((skip[0] == 'F') || (skip[0] == 'C'))
	{
		parse_color(skip, data);
		(*counter)++;
		return (1);
	}
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nNo such file");
	return (fd);
}

/**
 * @brief Parses the given file and store into the struct.
 *
 * This function opens the specified file, reads its contents line by line.
 * The first six lines are expected to contain identifiers, which are processed
 * and stored in the struct. After the identifiers, the function processes
 * the map data.
 * @param file The path to the file to be parsed.
 */
void	parser(char *file, t_game *data)
{
	char	*line;
	int		fd;
	int		counter;

	fd = open_file(file);
	counter = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (counter < 6)
		{	
			if (!identifier(line, data, &counter))
				error_exit("Error\nFirst six must be identifier");
			free(line);
		}
		else if (counter == 6 && blankstr(line))
			free(line);
		else
		{
			counter++;
			parse_map(line, data);
		}
	}
	close(fd);
}
