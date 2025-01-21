/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:12:29 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/19 12:12:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void put_pixel(int x, int y, int color, t_game *g)
{
	if (x >= 0 && x < g->width && y >= 0 && y < g->height)
		g->buff[y * g->width + x] = color;
}
