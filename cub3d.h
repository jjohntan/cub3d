/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:09:21 by jetan             #+#    #+#             */
/*   Updated: 2025/02/17 16:54:33by jetan            ###   ########.fr       */
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
int	parser(char *file, t_game *data);
//validate map
void	check_char(char **map);
void	check_walls(char **map);
void	flood_fill(char **map, int x, int y);
void	valid_map(char **map);
int	count_players(char **map);
void	valid_player(char **map);
void	parse_texture(char *line, t_game *data);
void	parse_color(char *line, t_game *data);
int	get_map_height(int fd);
int	is_map(char *line);

char	*skip_space(char *line);
#endif
