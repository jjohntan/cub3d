/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:37:42 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/19 18:37:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static bool	valid_txt(t_game *g);

/*
validate
===========================================================================
- validate texture, color and map data
- see individual function comments to see what checks being performed
- the raw data is being stored in t_game.info[] & t_game.map.ar

--------------------------------------------------------------------------
Access element info
- info[NO] = NO_texture
- info[SO] = SO_texture
- info[EA] = EA_texture
- info[WE] = WE_texture
- info[F]  = Floor_rgb
- info[C]  = Ceiling_rgb
*/
bool	validate(t_game *g)
{
	if (valid_txt(g) && valid_color(g) && valid_map(g))
		return (true);
	free_info(g->info);
	free_map(g->map.ar);
	return (false);
}

static bool	valid_txt(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!valid_file(g->info[i], ".xpm"))
			return (false);
	}
	return (true);
}
