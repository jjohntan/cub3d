/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:14 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/24 22:22:25 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "struct.h" 

//----------------------------------------------------------------------------
// Game
//----------------------------------------------------------------------------

// Initialize
void	init_asset(t_game *g);
void	init_minimap(t_game *g);

// Input + Movement
int		keypress(int key, t_game *g);
int		mouse_up(int button, int x, int y, t_game *g);
int		mouse_down(int button, int x, int y, t_game *g);
int		mouse_move(int x, int y, t_game *g);
void	rotational_motion(int key, t_game *g);
void	check_collision(int x, int y, t_game *g);

// Clean-up
int		closewind(t_game *g);
void	free_map(char **map);
void	free_asset(t_game *g);
void	free_texture(t_game *g);

//----------------------------------------------------------------------------
// Render
//----------------------------------------------------------------------------
int		render(t_game *g);
void	update_mini_img(t_game *g);

// Draw on canvas
void	draw_maze(t_game *g);
void	draw_player(t_game *g);
void	draw_minimap(t_game *g);
void	draw_weapon(t_game *g);
void	draw_bg(t_game *g);
void	draw_wall(t_game *g);

// Raycasting
void	raycast(t_game *g);
bool	check_wall(t_ray *ray, t_game *g);
void	update_point(t_ray *ray, float *step, int intercept);
float	x_intercept(float p, float angle, float *step);
float	y_intercept(float p, float angle, float *step);

//----------------------------------------------------------------------------
// Draw
//----------------------------------------------------------------------------
void	draw_line(int p[2], int end[2], int color, t_game *g);
void	draw_circle(int center[2], int r, int color, t_game *g);
void	draw_triangle(int x[3], int y[3], int color, t_game *g);
void	putpx_disp(int x, int y, int color, t_game *g);
void	putpx_img(int x, int y, int color, t_game *g);


//----------------------------------------------------------------------------
// Extract
//----------------------------------------------------------------------------
void	parser(char *file, t_game *data);
void	parse_texture(char *line, t_game *data);
void	parse_path(char *identify, char *path, t_game *data);
void	parse_color(char *line, t_game *data);
void	parse_rgb(char *path, int *value);
int		get_map_height(int fd);
int		is_map(char *line);
char	*skip_space(char *line);
void	get_map_width(t_game *data);

//----------------------------------------------------------------------------
// Validate
//----------------------------------------------------------------------------
void	check_char(char **map);
void	check_walls(char **map);
void	flood_fill(t_game *data, int x, int y);
void	valid_map(t_game *data);
void	count_players(t_game *data);
void	valid_player(t_game *data);
void	free_info(t_game *g);
void	valid_texture(t_game *data);
void	valid_color(t_game *data);
void	color_range(int *color);
void	check_color_format(char *str);

//----------------------------------------------------------------------------
// Utils
//----------------------------------------------------------------------------
void	err_msg(char *issue, char *expect, char *info);
float	angle_limit(float i);

void	error_exit(char *str);
float 	get_angle(char c);

int		check_dup_color(t_game *data);

#endif