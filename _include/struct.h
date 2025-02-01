/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:11 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/29 12:46:11 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "constant.h"

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


typedef struct s_maze
{
    char **arr;
    int x;
    int y;
} t_maze;

typedef struct s_mouse
{
    int x;
    bool enable;
}  t_mouse;


typedef struct s_game
{
    void *mlx;
    void *wind;

    t_mouse mouse;
    t_maze maze;
    t_minimap mini;
    t_display disp;
    t_player p1;
 
} t_game;


typedef struct s_img
{
    int bpp;
    int row;
    int end;
} t_img;

#endif