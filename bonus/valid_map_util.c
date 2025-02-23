/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:32:17 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/21 12:32:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static bool	init_player(char c, int x, int y, t_game *g);
static void	error_1(char *forbid_char);
static void	error_2(void);

/*
forbid_char
==============================================================================
- Only (space), 1, 0, W, E, N, S allowed
- Meantime check player pos and angle

------------------------------------------------------------------------------
Return
- true  : Contain forbidden char or more than 1 player
- false : ok
*/

bool	forbid_char(char *s, int y, t_game *g)
{
	int	x;

	x = -1;
	while (s[++x])
	{
		if (s[x] != '1' && s[x] != '0' && s[x] != ' ' && s[x] != 'W'
			&& s[x] != 'E' && s[x] != 'N' && s[x] != 'S')
		{
			return (error_1(s), true);
		}
		if (!init_player(s[x], x, y, g))
			return (error_2(), true);
	}
	return (false);
}

/*
inti_player
==============================================================================
Responsible to init player position and angle

Note: 
- player's uninitialized value is (0, 0)
- if not (0, 0), meaning already initialized

-----------------------------------------------------------------------------
Return
- true : successfully init or skip
- false: more that 1 player
*/

static bool	init_player(char c, int x, int y, t_game *g)
{
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
	{
		if (g->p1.x != 0 && g->p1.y != 0)
			return (false);
		if (c == 'N')
			g->p1.angle = DEG_270;
		else if (c == 'S')
			g->p1.angle = DEG_90;
		else if (c == 'E')
			g->p1.angle = 0;
		else if (c == 'W')
			g->p1.angle = DEG_180;
		g->p1.x = x * TILE + (TILE / 2);
		g->p1.y = y * TILE + (TILE / 2);
		g->p1.dx = cos(g->p1.angle);
		g->p1.dy = sin(g->p1.angle);
	}
	return (true);
}

static void	error_1(char *forbid_char)
{
	err_msg("Contain forbidden character",
		"(space), 1, 0, W, E, N, S allowed", forbid_char);
}

static void	error_2(void)
{
	err_msg("More than 1 player inside map", NULL, NULL);
}
