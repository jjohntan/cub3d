/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:13:51 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 13:52:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static void new_pos(float x, float y, t_game *g);
static void translational_motion(int key, t_game *g);
static void open_door(t_game *g);

//----------------------------------------------------------------------------

int keypress(int key, t_game *g)
{
    if (key == ESC)
        closewind(g);
    else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
        translational_motion(key, g);
    else if (key == AW_LEFT || key == AW_RIGHT)
        rotational_motion(key, g);
    else if (key == SPACEBAR)
        open_door(g);
    else if (key == NUM_1 && !g->attack)
        g->equip = 0;
    else if (key == NUM_2 && !g->attack)
        g->equip = 1;
    else if (key == VIEW)
        g->view = !g->view;
    return (0);
}

static void open_door(t_game *g)
{
    int x;
    int y;

    x = g->p1.x + REACH * g->p1.dx;
    y = g->p1.y + REACH * g->p1.dy;
    if (g->map.ar[y / TILE][x / TILE] == 'D')
    {
        g->map.ar[y / TILE][x / TILE] = 'U';
        update_mini_img(g);
    }
    else if (g->map.ar[y / TILE][x / TILE] == 'U' 
        && g->map.ar[(int)g->p1.y / TILE][(int)g->p1.x / TILE] != 'U')
    {
        g->map.ar[y / TILE][x / TILE] = 'D';
        update_mini_img(g);
    }
}

static void new_pos(float x, float y, t_game *g)
{
    g->p1.x += x * MOVE;
    g->p1.y += y * MOVE;
    check_collision(g->p1.x, g->p1.y, g);
}

static void translational_motion(int key, t_game *g)
{
    if (key == UP)
        new_pos(g->p1.dx, g->p1.dy, g);
    else if (key == DOWN)
        new_pos(-g->p1.dx, -g->p1.dy, g);
    else if (key == LEFT)
        new_pos(g->p1.dy, -g->p1.dx, g);
    else if (key == RIGHT)
        new_pos(-g->p1.dy, g->p1.dx, g);
}

void rotational_motion(int key, t_game *g)
{
    if (key == AW_LEFT)
        g->p1.angle = angle_limit(g->p1.angle - ROTATE);
    else if (key == AW_RIGHT)
        g->p1.angle = angle_limit(g->p1.angle + ROTATE);
    g->p1.dx = cos(g->p1.angle);
    g->p1.dy = sin(g->p1.angle);
}
