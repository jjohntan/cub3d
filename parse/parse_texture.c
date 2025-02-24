/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:13:24 by jetan             #+#    #+#             */
/*   Updated: 2025/02/24 22:18:15 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

// /**
//  * @brief This function check the colors range in [0,255]
//  */
// static void	color_range(int *color)
// {
// 	int	i;

// 	if (!color)
// 		return ;
// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (color[i] < 0 || color[i] > 255)
// 			error_exit("Error\nInvalid color range");
// 		i++;
// 	}
// }

// /**
//  * @brief This function check the color format
//  */
// void	check_color_format(char *str)
// {
// 	int	i;
// 	int	comma;

// 	i = 0;
// 	comma = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ',')
// 		{
// 			comma++;
// 			i++;
// 		}
// 		else if (ft_isdigit(str[i]) != 0)
// 			i++;
// 		else
// 			error_exit("Error\nInvalid character");
// 	}
// 	if (comma != 2)
// 		error_exit("Error\ntwo comma needed");
// }

// /**
//  * @brief This function convert rgb from decimal to hexadecimal
//  */
// int	color(int r, int g, int b)
// {
// 	return ((r << 16) | (g << 8) | (b));
// }



// /**
//  * @brief trimmed_line: identifier
//  * 
//  * This function parse color into struct
//  */
// void	parse_color(char *line, t_game *data)
// {
// 	char	*trimmed_line;
// 	char	*path;
// 	char	**color_value;//free
// 	int		rgb[3];

// 	trimmed_line = line;
// 	line += 1;
// 	path = ft_strtrim(line, " \t\n");
// 	check_color_format(path);
// 	color_value = ft_split(path, ',');
// 	rgb[0] = ft_atoi(color_value[0]);
// 	rgb[1] = ft_atoi(color_value[1]);
// 	rgb[2] = ft_atoi(color_value[2]);
// 	color_range(rgb);
// 	if (ft_strncmp(trimmed_line, "F", 1) == 0)
// 	{
// 		data->floor = color(rgb[0], rgb[1], rgb[2]);
// 		printf("floor: %d\n", data->floor);//
// 	}
// 	else if (ft_strncmp(trimmed_line, "C", 1) == 0)
// 	{
// 		data->ceiling = color(rgb[0], rgb[1], rgb[2]);
// 		printf("ceiling: %d\n", data->ceiling);//
// 	}
// }

/**
 * @brief This function store texture path into struct follow by indentifier
 */
void	parse_texture(char *line, t_game *data)
{
	char	*identify;
	char	*path;

	identify = line;
	line += 2;
	path = ft_strtrim(line, " \t\n");
	if (ft_strncmp(identify, "NO", 2) == 0)
	{
	    if (data->no)
			error_exit("Error\nDuplicate data\n");
		data->no = path;
		printf("NO:%s\n", data->no);//hi
	}
	else if (ft_strncmp(identify, "SO", 2) == 0)
	{
		if (data->so)
			error_exit("Error\nDuplicate data\n");
		data->so = path;
		printf("SO:%s\n", data->so);//hi
	}
	else if (ft_strncmp(identify, "WE", 2) == 0)
	{
		if (data->we)
			error_exit("Error\nDuplicate data\n");
		data->we = path;
		printf("WE:%s\n", data->we);//hi
	}
	else if (ft_strncmp(identify, "EA", 2) == 0)
	{
		if (data->ea)
			error_exit("Error\nDuplicate data\n");
		data->ea = path;
		printf("EA:%s\n", data->ea);//hi
	}
}
