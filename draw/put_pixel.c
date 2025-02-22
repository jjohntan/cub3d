/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:32:06 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/01 20:32:06 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void putpx_disp(int x, int y, int color, t_game *g)
{
    if (x >= 0 && x < WIND_W && y >= 0 && y < WIND_H)
        g->disp.buf[y * WIND_W + x] = color; 
}

void putpx_img(int x, int y, int color ,t_game *g)
{
    if (x >= 0 && x < g->mini.w && y >= 0 && y < g->mini.h)
        g->mini.buf[y * g->mini.w + x] = color; 
}
