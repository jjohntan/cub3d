/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:31:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/26 15:24:51 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/**
 * @brief This function check the colors range in [0,255]
 */
bool	color_range(int *color)
{
	int	i;

	if (!color)
		return (false);
	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief This function check the color format
 */
void	check_color_format(char *str, t_game *data)
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
		else if (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		else
			error_exit("Color: Invalid character", data);
	}
	if (comma != 2)
		error_exit("Color: Two commas needed", data);
}

void	valid_color(t_game *data)
{
	if (!data->c || !data->f)
		error_exit("Color: Missing info", data);
	parse_rgb(data->c, &data->ceiling, data);
	parse_rgb(data->f, &data->floor, data);
}
