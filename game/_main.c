/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:38:34 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/29 12:38:34 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

int main()
{
    t_game g;
    
    init(&g);
    //mlx_put_image_to_window(g.mlx, g.wind, g.mini.ptr, 0, 0);
    
    mlx_hook(g.wind, 4, 1L<<2, mouse_down, &g);
    mlx_hook(g.wind, 5, 1L<<3, mouse_up, &g);
    mlx_hook(g.wind, 6, 1L<<6, mouse_move, &g);

    mlx_hook(g.wind, 2, 1L<<0, keypress, &g);
	mlx_hook(g.wind, 17, 1L<<17, closewind, &g);
    mlx_loop_hook(g.mlx, render, &g);
	mlx_loop(g.mlx);
}
