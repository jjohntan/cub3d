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

static int	animate(t_game *g);
static void	put_img(int x, int y, int frame, t_game *g);

// Sprite 300 x 200

void	draw_weapon(t_game *g)
{
	int	xoffset;
	int	yoffset;

	yoffset = WIND_H - SPRITE_H;
	xoffset = (WIND_W / 2) - (SPRITE_W / 2);
	put_img(xoffset, yoffset, animate(g), g);
}

static void	put_img(int x, int y, int frame, t_game *g)
{
	int	i;
	int	j;
	int	xmin;
	int	*buf;

	j = -1;
	xmin = x;
	buf = g->weapon[g->equip][frame].buf;
	while (++j < SPRITE_H)
	{
		i = -1;
		x = xmin;
		while (++i < SPRITE_W)
		{
			if ((unsigned int)buf[j * SPRITE_W + i] != VOID)
				putpx_disp(x, y, buf[j * SPRITE_W + i], g);
			x++;
		}
		y++;
	}
}

static int	animate(t_game *g)
{
	int	i;

	if (g->attack)
	{
		i = (g->timer++) / 10;
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
