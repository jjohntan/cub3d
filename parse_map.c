/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/18 22:03:31 by jetan            ###   ########.fr       */
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

char	*skip_space(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] == ' ' || line [i] == '\t')
		i++;
	return (&line[i]);
}

int blankstr(char *str)
{
	while(*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}

/*
- true : is an element  >> extract >> increment counter (max 6)
- false: not an element >> err_msg
- true : blank >> but no increment 
*/
static int	identifier(char *line, t_game *data, int *counter)
{
	char	*skip;

	skip = skip_space(line);
	if (blankstr(line))
		return (1);
	if ((skip[0] == 'N' && skip[1] == 'O') ||
	 (skip[0] == 'S' && skip[1] == 'O') ||
	 (skip[0] == 'W' && skip[1] == 'E') ||
	 (skip[0] == 'E' && skip[1] == 'A'))
	 {
		parse_texture(skip, data);
		(*counter)++;
		return (1);
	 }
	else if ((skip[0] == 'F') ||
	 (skip[0] == 'C'))
	 {
		parse_color(skip, data);
		(*counter)++;
		return (1);
	 }
	return (0);
}

void freelist(char **list)
{
	int i = 0;
	if (!list)
		return ;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void parse_map(char *line, t_game *data)
{
	char	**temp;
	int		i;
	
	i = 0;
	temp = (char **)malloc(sizeof(char *) * (++data->map.y + 1));
	while (data->map.arr && data->map.arr[i])
	{
		temp[i] = data->map.arr[i];
		i++;
	}
	temp[i++] = line;
	temp[i] = NULL;
	
	// if (data->map.arr)
	// 	freelist(data->map.arr);
	data->map.arr = temp;
}

/*
1 = success
0 = false
*/
int	parser(char *file, t_game *data)
{
	int		fd;
	char	*line;
	
		int counter;
		counter = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo such file", 2);
		return (0);
	}
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (counter < 6)
		{	
			if (!identifier(line, data, &counter))
				return (printf("Dont suppose to execute\n"), 0);
			free(line);
		}
		else if (counter == 6 && blankstr(line))
			free(line);
		else
		{
			counter++; 
			parse_map(line, data);
		}
		//printf("%d | %s", counter, line);//hello
	}
	close(fd);
	return (1);
}
