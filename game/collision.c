/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:43:04 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 11:36:11 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

bool	is_wall(int x, int y, t_game *g)
{
	char	c;

	c = g->map.ar[y / TILE][x / TILE];
	if (c == '1' || c == 'D')
		return (true);
	return (false);
}

void	check_collision(int x, int y, t_game *g)
{
	if (is_wall(x + BOUND, y, g))
		g->p1.x = ((x + BOUND) / TILE) * TILE - BOUND;
	if (is_wall(x - BOUND, y, g))
		g->p1.x = ((x - BOUND) / TILE) * TILE + TILE + BOUND;
	if (is_wall(x, y + BOUND, g))
		g->p1.y = ((y + BOUND) / TILE) * TILE - BOUND;
	if (is_wall(x, y - BOUND, g))
		g->p1.y = ((y - BOUND) / TILE) * TILE + TILE + BOUND;
}
