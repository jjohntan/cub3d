/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:55:13 by jetan             #+#    #+#             */
/*   Updated: 2025/02/21 17:39:34 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief
 * count_players - Counts the number of players in the game map
 * and updates player data.
 * This function iterates through the map to find
 * player positions marked by 'N', 'S', 'E', or 'W'.
 * For each player found, it increments the player count
 * and updates the player's coordinates and angle.
 */
void	count_players(t_game *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map.arr[row])
	{
		col = 0;
		while (data->map.arr[row][col])
		{
			if (ft_strchr("NSEW", data->map.arr[row][col]))
			{
				data->p1.player_count++;
				data->p1.y = row;
				data->p1.x = col;
				data->p1.angle = data->map.arr[row][col];
				printf("player count: %d\n", data->p1.player_count);//hello
				printf("player y: %d\n", data->p1.y);//hello
				printf("player x: %d\n", data->p1.x);//hello
				printf("player angle: %f\n", data->p1.angle);//hello
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

// static void free_list(char **list)
// {
// 	int i = 0;
// 	if (!list)
// 		return ;
// 	while (list[i])
// 	{
// 		free(list[i]);
// 		i++;
// 	}
// 	free(list);
// }

/**
 * @param str: error message
 * @brief This function return a error message and exit the program
 */
void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	get_map_width(t_game *data)
{
	int	len;
	int	i;

	i = -1;
	while (data->map.arr[++i] != NULL)
	{
		len = ft_strlen(data->map.arr[i]);
		if (len > data->map.width)
			data->map.width = len;
	}

}
