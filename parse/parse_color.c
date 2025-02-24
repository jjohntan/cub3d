/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:13:47 by jetan             #+#    #+#             */
/*   Updated: 2025/02/24 22:22:45 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/**
 * @brief This function check the colors range in [0,255]
 */
static void	color_range(int *color)
{
	int	i;

	if (!color)
		return ;
	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			error_exit("Error\nInvalid color range");
		i++;
	}
}

/**
 * @brief This function check the color format
 */
void	check_color_format(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			comma++;
			i++;
		}
		else if (ft_isdigit(str[i]) != 0)
			i++;
		else
			error_exit("Error\nInvalid character");
	}
	if (comma != 2)
		error_exit("Error\ntwo comma needed");
}

// int	check_dup_color(t_game *data)
// {
// 	if (data->floor != )
// 		return (0);
// 	else if (data->ceiling != )
// 		return (0);
// 	return (1);
// }

/**
 * @brief This function convert rgb from decimal to hexadecimal
 */
int	color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

void	parse_rgb(char *path, int *value)
{
	int	rgb[3];
	char **color_value;
	
	check_color_format(path);
	color_value = ft_split(path, ',');
	rgb[0] = ft_atoi(color_value[0]);
	rgb[1] = ft_atoi(color_value[1]);
	rgb[2] = ft_atoi(color_value[2]);
	color_range(rgb);
	*value = color(rgb[0], rgb[1], rgb[2]);
	free(color_value[0]);
	free(color_value[1]);
	free(color_value[2]);

}

/**
 * @brief identify: identifier
 * 
 * This function parse color into struct
 */
void	parse_color(char *line, t_game *data)
{
	char	*identify;
	char	*path;

	identify = line;
	path = ft_strtrim(line + 1, " \t\n");
	if (ft_strncmp(identify, "F", 1) == 0)
	{
		if (data->f)
			error_exit("Error\nDuplicate color");
		data->f = path;
	}
	else if (ft_strncmp(identify, "C", 1) == 0)
	{
		if (data->c)
			error_exit("Error\nDuplicate color");
		data->c = path;
	}
}

void valid_color(t_game *data)
{
	if (!data->c || !data->f)
		error_exit("Error\nMissing color info\n");
	parse_rgb(data->c, &data->ceiling);
	parse_rgb(data->f, &data->floor);
}