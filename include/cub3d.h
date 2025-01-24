/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:58:13 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/20 16:30:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// =========================================================================
// LIBRARY
// =========================================================================

# include <fcntl.h>     // open, close
# include <unistd.h>    // read, write
# include <stdio.h>     // printf, perror
# include <string.h>    // strerror (Also need errno)
# include <error.h>
# include <stdlib.h>    // exit, malloc, free 
# include <math.h>      // All math function
# include <stdbool.h>   // true ,false
# include "mlx/mlx.h"   // All Minilibx functions
# include "lib/libft.h" // libft authorize
# include <X11/keysym.h>
# include <X11/X.h>

// =========================================================================
// CONSTANT
// =========================================================================

// Color
# define GREY 0xA9A9A9
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define BLACK 0x0

//Keyboard
# define ESC 65307
# define AW_LEFT 65361
# define AW_RIGHT 65363
# define UP 119    // W
# define DOWN 115  // S
# define LEFT 97   // A
# define RIGHT 100 // D

// Quadrant
#define PI 3.14159265358979323846 
# define DEG_90 (PI / 2)
# define DEG_180 (PI)
# define DEG_270 (3 * PI) / 2
# define DEG_360 (2 * PI)

// Window
# define W 1024
# define H 512
# define FOV 1.15192
# define SCREEN (W / 2)
# define ANGLE_STEP (FOV / SCREEN)

// 2D Map
# define X 0
# define Y 1
# define CELL 64

// Player
# define MV_STEP 4.0
# define RT_STEP 0.05

// Direction
# define NORTH DEG_270
# define SOUTH DEG_90
# define EAST DEG_180
# define WEST 0

// DDA calculation
# define X_INTER 1 
# define Y_INTER 2

// =========================================================================
// STRUCT
// =========================================================================

typedef struct s_game
{
	void *mlx;
	void *wind;
    
    // Player
    float pos[2];
    float angle;
    float dir[2];

    // Mouse movement
    int xpoint;
    int ypoint;

    // Buffer img to draw on
    void *display;
	int *buff;
    int bpp;
    int row;
    int endian;

    // 2D map
    char *map[9];
    int which_cal;

    float wall[SCREEN];
}	t_game;

// =========================================================================
// PROTOTYPE
// =========================================================================

// Setup
void init(t_game *g);
int render(t_game *g);
void config(t_game *g);
int closewind(t_game *g);

// Input
int mouse(int x, int y, t_game *g);
int keyboard(int key, t_game *g);
void limit_range(t_game *g);

// Render
void draw_on_canvas(t_game *g);
void background(t_game *g);
void player(t_game *g);
void map(t_game *g);
void raycast(t_game *g);

// Utils
void put_pixel(int x, int y, int color, t_game *g);
void draw_line(int start[2], int end[2], int color, t_game *g);
void draw_rect(int start[2], int end[2], int color, t_game *g);
float angle(float i);

// Raycast utils
bool y_only(float a);
bool x_only(float a);
int update_point(float *p ,float *step, int which_cal);
float x_intercept(float *p, float *step, float angle);
float y_intercept(float *p, float *step, float angle);

#endif