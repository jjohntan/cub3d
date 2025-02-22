/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:33 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 19:27:19 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"
static bool error_1(int count);

/*
check_in
=============================================================================
check the program's input
- ensure only argument 1
- ensure that argument is the game_scene_file

-----------------------------------------------------------------------------
Return
- true : OK
- false: either wrong argument count or not a game_scene file

*/
bool check_in(int ac, char **av)
{
    if ((ac != 2 && error_1(ac)) || !valid_file(av[1], ".cub"))
        return (false);
    return (true);
}

static bool error_1(int count)
{   
    char *s;

    if (count > 2)
        s = "Enter more that 1 argument";
    else
        s = "Please enter the scene_config_file";
    err_msg(s, "./cub3d scene.cub", NULL);
    return (true);
}