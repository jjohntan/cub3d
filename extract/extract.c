/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:33:40 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 23:21:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static bool	read_content(int fd, t_game *g);
static bool	all_fill(t_game *g);
static void	error_1(char *missing);

/*
extract
=============================================================================
- open the scene_file and extract the data
- check all necessary data filled (not NULL)

----------------------------------------------------------------------------
Extraction method
- extract_1: extract first 6 none_empty string with identifier_substring
- extract_2: extract the last data which is the map

-----------------------------------------------------------------------------
Return
- true  : successful extraction
- false : fail extraction - only extract_1 throw error (see extract_1)
*/

bool	_extract(char *filename, t_game *g)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (read_content(fd, g) && all_fill(g))
		return (close(fd), true);
	return (close(fd), free_info(g->info), free_map(g->map.ar), false);
}

static bool	read_content(int fd, t_game *g)
{
	int		i;
	char	*line;

	i = 0;
	while (read_line(fd, &line))
	{
		if (i < 6)
		{
			if (!extract_1(line, &i, g))
				return (free(line), flush_gnl(fd), false);
			free(line);
		}
		else if (i == 6 && blankstr(line))
			free(line);
		else
			i += extract_2(line, g);
	}
	return (true);
}

static bool	all_fill(t_game *g)
{
	if (!g->info[NO] || !g->info[NO][0])
		return (error_1("[North texture]"), false);
	if (!g->info[SO] || !g->info[SO][0])
		return (error_1("[South texture]"), false);
	if (!g->info[EA] || !g->info[EA][0])
		return (error_1("[East texture]"), false);
	if (!g->info[WE] || !g->info[WE][0])
		return (error_1("[West texture]"), false);
	if (!g->info[C] || !g->info[C][0])
		return (error_1("[Ceiling color]"), false);
	if (!g->info[F] || !g->info[F][0])
		return (error_1("[Floor color]"), false);
	if (!g->map.ar)
		return (error_1("[Map]"), false);
	return (true);
}

static void	error_1(char *missing)
{
	char	*s;

	s = ft_strjoin("Missing data for ", missing);
	err_msg(s, NULL, NULL);
	free(s);
}
