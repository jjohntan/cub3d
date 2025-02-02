/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:15:59 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 13:36:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

void init(t_game *g)
{
    ft_memset(g, 0, sizeof(t_game));
    g->mlx = mlx_init();
	g->wind = mlx_new_window(g->mlx, WIND_W, WIND_H, "Cub3D");
    g->ceiling = CEILING;
    g->floor = FLOOR;
    g->maze.arr = use_dummy_maze();
    get_maze_info(g);
    get_asset(g);
    init_minimap(g);
    
}
