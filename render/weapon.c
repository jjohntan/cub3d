/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:30:18 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 14:59:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
int animate(t_game *g);

//----------------------------------------------------------------------------

// Sprite 300 x 200
void draw_weapon(t_game *g)
{
    int i;
    int j;
    int x;
    int xmin;
    int y;
    int *buf;
    int a;

    j = -1;
    y = WIND_H - 200;
    xmin = WIND_W / 2 - 150;
    a = animate(g);
    while (++j < 200)
    {
        i = -1;
        x = xmin;
        while (++i < 300)
        {
            buf = g->weapon[g->equip][a].buf;
            if ((unsigned int)buf[j * 300 + i] != 0xFF000000)
                putpx_disp(x, y, buf[j * 300 + i], g);
            x++;
        }
        y++;
    }
}

int animate(t_game *g)
{
    int i;

    if (g->attack)
    {
        i = (g->timer++) / 7;
        if (g->weapon[g->equip][i + 1].ptr)
            return (i + 1);
        else
        {
            g->attack = false;
            g->timer = 0;
        }
    }
    return (0);
}
