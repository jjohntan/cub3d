/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:09:21 by jetan             #+#    #+#             */
/*   Updated: 2025/02/07 19:30:08 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
#include <fcntl.h>
# include <stdbool.h>
#include "struct.h"
//parse map
int	parse_map(char *file, t_game *data);
//validate map
void	check_char(char **map);
void	check_walls(char **map);
void	flood_fill(char **map, int x, int y);
void	valid_map(char **map);
int	count_players(char **map);
void	valid_player(char **map);
void	parse_texture(char *line, t_game *data);
#endif
