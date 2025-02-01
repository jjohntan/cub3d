/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:32:29 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/31 20:32:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void draw_circle(int center[2], int r, int color, t_game *g)
{
    int y;
    int x;
    int left;
    int right;

    y = center[Y] - r - 1;
    while (++y <= center[Y] + r) 
    {
        x = center[X] - r - 1;
        while (++x <= center[X] + r) 
        {
            left = pow(x - center[X], 2) + pow(y - center[Y], 2);
            right = pow(r, 2);
            if (left < right) 
                putpx_disp(x, y, color, g);
        }
    }
}
