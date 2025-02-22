/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:40 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/19 11:58:40 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../_include/cub3d.h"
static void init_label(char **label);
static void error_1(char *duplicate_id);
static void error_2(char *no_id);

/*
extract_1
============================================================================
- ignore row space
- determine what identifier and store data in the correct struct
- trim white_space and identifier, then strdup() the portion that we need

Note: 
- The first 6 data need futher processing -> not needed for game
- After parse and init game can free them

--------------------------------------------------------------------------
Sample data

- Identifier
- ↓ 
- EA textures/test/east.xpm
-         ↑
-  What we need

--------------------------------------------------------------------------
Step

1) check str not blank 
2) check str have identifier and location to store is NULL
---> throw error if repeated or no identifier

3) trim identifier and white space, then strdup() portion we need
4) Increment counter and return

---------------------------------------------------------------------------
Param
- char *s : string from gnl
- int *i  : reference pointer to track extraction count (stop at no. 6)

--------------------------------------------------------------------------
Return 
- true  : OK
- false : the first 6 data is repeated or no identifier

*/
bool extract_1(char *s, int *track, t_game *g)
{
    int i;
    int len;
    char *label[7];

    i = -1;
    s = trim_space(s, L_TRIM);
    if (!(*s))
        return (true);
    init_label(label);
    while (label[++i])
    {
        len = ft_strlen(label[i]);
        if (ft_strncmp(s, label[i], len) == 0)
        {
            if (g->info[i])
                return (error_1(s), false);
            g->info[i] = ft_strdup(trim_space(s + len, BOTH));
            return ((*track)++, true);
        }
    }
    return (error_2(s), false);
}

static void init_label(char **label)
{
    label[0] = "NO ";
    label[1] = "SO ";
    label[2] = "EA ";
    label[3] = "WE ";
    label[4] = "F ";
    label[5] = "C ";
    label[6] = NULL;
}

static void error_1(char *duplicate_id)
{
    err_msg("Duplicate element identifier", 
        "Only can have 1 for each identifier", duplicate_id);
}

static void error_2(char *no_id)
{
    err_msg("No or incorrect identifier", 
        "<element> string\n           Element: NO, SO, WE, EA, C, F"
        , no_id);
}


