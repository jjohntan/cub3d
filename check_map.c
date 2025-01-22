/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:51 by jetan             #+#    #+#             */
/*   Updated: 2025/01/22 17:20:56 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_walls(char **map)
{
	int	i;
	int	j;
	
	int h = 5;
	int w = 6;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (i == 0 || i == h - 1 ||
			j == 0 || j == w - 1)
			{
				if (map[i][j] != '1')
				{
					ft_putstr_fd("Error\nmap must be closed by walls", 2);
					return ;
				}
			}
			j++;
		}
		i++;
	}
}
