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
void	parser(char *file, t_game *data);
//validate map
void	check_char(char **map);
void	check_walls(char **map);
void	flood_fill(t_game *data, int x, int y);
void	valid_map(t_game *data);
void	count_players(t_game *data);
void	valid_player(t_game *data);
void	parse_texture(char *line, t_game *data);
void	parse_color(char *line, t_game *data);
int	get_map_height(int fd);
int	is_map(char *line);

char	*skip_space(char *line);
void	error_exit(char *str);
void	valid_texture(t_game *data);
void	get_map_width(t_game *data);
#endif
