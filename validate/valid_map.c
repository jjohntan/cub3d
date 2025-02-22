/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:07:37 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/21 10:07:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static void error_1();
static void error_2();
static void error_3();
static void error_4();

/*
valid_map
=============================================================================
- map array size must be atleat 3 x 3
    111
    1N1
    111
- No blank string inside the map
- No forbidden characters. Only '1' '0' '(space)' 'W' 'S' 'E' 'N' --> Bonus="D"
    * At same time, get player pos
    * Player can only init 1 time
- Perform floor fill to check if map surrounded with "walls"
*/
bool valid_map(t_game *g)
{
    int y;

    y = -1;
    if (g->map.x < 3 || g->map.y < 3)
        return (error_1(), false);
    while (g->map.ar[++y])
    {
        if (blankstr(g->map.ar[y]))
            return (error_2(), false);
        if (forbid_char(g->map.ar[y], y, g))
            return (false);
    }
    if (g->p1.x == 0 && g->p1.y == 0)
        return (error_3(), false);
    if (map_leak(g))
        return (error_4(), false);
    return (true);
}

static void error_1()
{
    err_msg("Invalid map. Size too small"
        , "Map array size must be atleat 3 x 3", NULL);
}

static void error_2()
{
    err_msg("Incomplete map"
        , "Forbid blank string inside map", NULL);
}

static void error_3()
{
    err_msg("No player found inside map", NULL, NULL);
}

static void error_4()
{
    err_msg("Map not surrounded with walls", NULL, NULL);
}

/*
int main()
{
    t_game g;

    char *map[9];
    char r1[] = "111111111111";
    char r2[] = "1           ";
    char r3[] = "1       0001";
    char r4[] = "1000000 0011";
    char r5[] = "10000E000001";
    char r6[] = "111111111111";
    char r7[] = "1          1";
    char r8[] = "111111111111";

    map[0] = r1;
    map[1] = r2;
    map[2] = r3;
    map[3] = r4;
    map[4] = r5;
    map[5] = r6;
    map[6] = r7;
    map[7] = r8;
    map[8] = NULL;
    
    g.map.ar = map;
    g.map.x = ft_strlen(map[4]);
    g.map.y = 8;

    if (valid_map(&g))
    {
        printf("X:%f\n Y:%f\nAngle:%f\n", g.p1.x ,g.p1.y, g.p1.angle);
    }
}
*/