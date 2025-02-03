/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:56:50 by jetan             #+#    #+#             */
/*   Updated: 2025/02/03 20:38:43 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_char(char **map)
{
	int	h;
	int	w;
	
	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[h][w])
		{
			if (map[h][w] != '0'&& map[h][w] != '1' && map[h][w]!= 'N' && map[h][w]!= 'S' && map[h][w]!='E' && map[h][w]!= 'W' && map[h][w] != 'D')
			{
				ft_putstr_fd("Error\nInvalid character in map", 2);
				return ;
			}
			w++;
		}
		h++;
	}
}