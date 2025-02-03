/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:09:21 by jetan             #+#    #+#             */
/*   Updated: 2025/02/03 15:50:53 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_map
{
	int	height;
	int	width;
	
}	t_map;


typedef struct s_data
{
	t_map	*map;
}	t_data;

void	check_char(char **map);
void	check_walls(char **map);
void	flood_fill(char **map, int x, int y);
void	valid_map(char **map);
#endif