/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:30:47 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 13:49:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

int mouse_up(int button, int x, int y, t_game *g)
{
    (void)x;
    (void)y;
    if (button == LEFT_CLICK)
        g->mouse.enable = false;
    return (0);
}

int mouse_down(int button, int x, int y, t_game *g)
{
    (void)y;
    if (button == LEFT_CLICK)
    {
        g->mouse.enable = true;
        g->mouse.x = x;
    }
     else if (button == RIGHT_CLICK)
        g->attack = true;
    return (0);
}

int mouse_move(int x, int y, t_game *g)
{
    int diff;

    (void)g;
    (void)y;
    if (g->mouse.enable)
    {
        diff =  x - g->mouse.x;
        if (diff > DIFF || diff < -DIFF)
        {
            if (diff < 0)
                rotational_motion(AW_LEFT, g);
            else
                rotational_motion(AW_RIGHT, g);
            g->mouse.x = x;
        }
    }
    return (0);
}
