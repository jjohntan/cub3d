/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:14 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/11 20:01:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "struct.h" 

//----------------------------------------------------------------------------
// Game
//----------------------------------------------------------------------------

// Initialize
bool	check_in(int ac, char **av);
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
void	free_info(char **info);
void	free_asset(t_game *g);

//----------------------------------------------------------------------------
// Extract
//----------------------------------------------------------------------------
bool	_extract(char *filename, t_game *g);
bool	extract_1(char *s, int *track, t_game *g);
int		extract_2(char *s, t_game *g);
bool	read_line(char fd, char **s);
void	flush_gnl(int fd);

//----------------------------------------------------------------------------
// Validate
//----------------------------------------------------------------------------

// Validate input
bool	validate(t_game *g);
bool	valid_map(t_game *g);
bool	valid_color(t_game *g);
bool	valid_file(char *filename, char *ext);

// Valid color utils
bool	check_comma(char *s);
void	split_rgb(char *s, char **split);
bool	valid_num(char **color);
bool	in_range(char **color, int *num);
int		rgb_2_color(int r, int g, int b);

// Valid map utils
bool	forbid_char(char *s, int y, t_game *g);
bool	map_leak(t_game *g);

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
// Utils
//----------------------------------------------------------------------------
bool	blankstr(char *s);
char	*trim_space(char *s, int option);
void	err_msg(char *issue, char *expect, char *info);
float	angle_limit(float i);
int		print(char *s);

#endif