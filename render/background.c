/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:36:59 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 13:42:27 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void draw_bg(t_game *g)
{
    int x;
    int y;

    y = -1;
    while (++y < WIND_H)
    {
        x = -1;
        while (++x < WIND_W)
        {
            if (y < WIND_H / 2)
                putpx_disp(x, y, g->ceiling, g);
            else
                putpx_disp(x, y, g->floor, g);
        }
    }
}
