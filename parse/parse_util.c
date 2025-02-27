/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:55:13 by jetan             #+#    #+#             */
/*   Updated: 2025/02/26 15:40:02 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/**
 * @brief
 * count_players - Counts the number of players in the game map
 * and updates player data.
 * This function iterates through the map to find
 * player positions marked by 'N', 'S', 'E', or 'W'.
 * For each player found, it increments the player count
 * and updates the player's coordinates and angle.
 */

float	get_angle(char c)
{
	if (c == 'N')
		return (DEG_270);
	else if (c == 'S')
		return (DEG_90);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (DEG_180);
	return (-1);
}

/**
 * @brief This function loop though the map find player
 * stating position and update player data
 */
void	count_players(t_game *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map.ar[row])
	{
		col = 0;
		while (data->map.ar[row][col])
		{
			if (ft_strchr("NSEW", data->map.ar[row][col]))
			{
				data->p1.player_count++;
				data->p1.y = row * TILE + (TILE / 2);
				data->p1.x = col * TILE + (TILE / 2);
				data->p1.angle = get_angle(data->map.ar[row][col]);
			}
			col++;
		}
		row++;
	}
}

/**
 * @brief This function skip all the space and tabspace
 */
char	*skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line [i] == '\t' || line[i] == '\n')
		i++;
	return (&line[i]);
}

/**
 * @param str: error message
 * @brief This function return a error message and exit the program
 */
void	error_exit(char *str, t_game *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (data)
	{
		free_map(data->map.ar);
		free_map(data->map.tmp);
		free_info(data);
	}	
	exit(1);
}

/**
 * @brief This function get the maximum map width
 */
void	get_map_width(t_game *data)
{
	int	len;
	int	i;

	i = -1;
	while (data->map.ar[++i] != NULL)
	{
		len = ft_strlen(data->map.ar[i]);
		if (len > data->map.w)
			data->map.w = len;
	}
}
