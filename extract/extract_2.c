/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:27:53 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/19 14:27:53 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/*
==============================================================================
- extract the last data which is the map
- not error checking here, extract as is
- at same time get the map array x, y size

Note: No strdup here, so no need to free() the line

----------------------------------------------------------------------------
Return 
- alway return = 1
*/
int extract_2(char *s, t_game *g)
{
    int i;
    char **temp;

    i = 0;
    s = trim_space(s, R_TRIM);
    temp = (char **)malloc(sizeof(char *) * (++g->map.y + 1));
    while (g->map.ar && g->map.ar[i])
    {
        temp[i] = g->map.ar[i];
        i++;
    }
    temp[i++] = s;
    temp[i] = NULL;
    if ((int)ft_strlen(s) > g->map.x)
        g->map.x = ft_strlen(s);
    if (g->map.ar)
        free(g->map.ar);
    g->map.ar = temp;
    return (1);
}