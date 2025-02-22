/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:11 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/10 22:47:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "constant.h"

typedef struct s_img
{
    int bpp;
    int row;
    int end;
    int w;
    int h;
} t_img;

typedef struct s_minimap
{
    void *ptr;
    int *buf;
    int w;
    int h;
} t_minimap;

typedef struct s_display
{
    void *ptr;
    int *buf;
} t_display;

typedef struct s_player
{
    float x;
    float y;
    float angle;
    float dx;
    float dy;
} t_player;

typedef struct s_map
{
    char **ar;
    int x;
    int y;
} t_map;

typedef struct s_mouse
{
    int x;
    bool enable;
}  t_mouse;

typedef struct s_weapon
{
    void *ptr;
    int *buf;
    bool end;
} t_weapon;

typedef struct s_texture
{
    void *ptr;
    int *buf;
    bool end;
} t_texture;

typedef struct s_ray
{
    float x;
    float y;
    float angle;
    int intercept;
    bool door;
    int wall_h;
    int which_tx;
} t_ray;

typedef struct s_game
{
    void *mlx;
    void *wind;
    int ceiling;
    int floor;
    bool view;

    bool attack;
    int equip;
    int timer;

    char *info[7];
    t_ray ray[WIND_W];
    t_texture texture[6];
    t_weapon weapon[2][6];
    t_mouse mouse;
    t_map map;
    t_minimap mini;
    t_display disp;
    t_player p1;
 
} t_game;


#endif