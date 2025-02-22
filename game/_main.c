/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:38:34 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/02 12:01:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static void init(int ac, char **av, t_game *g)
{
    ft_memset(g, 0, sizeof(t_game));
    if (!check_in(ac, av) || !_extract(av[1], g) || !validate(g))
        exit(EXIT_FAILURE);
    g->mlx = mlx_init();
	g->wind = mlx_new_window(g->mlx, WIND_W, WIND_H, "Cub3D");
    init_asset(g);
    init_minimap(g);
}

void show_control()
{
    ft_printf("  ____ _   _ ____    _____ ____   \n");
    ft_printf(" / ___| | | | __ )  |___ /|  _ \\ \n");
    ft_printf("| |   | | | |  _ \\    |_ \\| | | |\n");
    ft_printf("| |___| |_| | |_) |  ___) | |_| |\n");
    ft_printf(" \\____|\\___/|____/  |____/|____/ \n");
    ft_printf("\n🎮 CONTROLS 🎮\n\n");
    ft_printf("🏃 Movement\n============\n"); 
    ft_printf("W, A, S, D\n\n");  
    ft_printf("🎥 Look Around\n================\n");  
    ft_printf("⬅️  AND ➡️ \n");
    ft_printf("or\n");
    ft_printf("🖱 Hold Left Click + Drag\n\n");
    ft_printf("🔫 Combat\n=========\n");
    ft_printf("Knife  : 1️⃣ \n"); 
    ft_printf("Pistol : 2️⃣ \n");  
    ft_printf("Attack :🖱 Right Click\n\n");
    ft_printf("⚙️  Others\n==========\n");
    ft_printf("Change View : V \n"); 
    ft_printf("Unlock Door : Spacebar\n"); 
    ft_printf("Quit Game   : ESC or window red ❌ \n\n"); 
}

int main(int ac, char **av)
{
    t_game g;
    
    init(ac, av, &g);
    mlx_hook(g.wind, 4, 1L<<2, mouse_down, &g);
    mlx_hook(g.wind, 5, 1L<<3, mouse_up, &g);
    mlx_hook(g.wind, 6, 1L<<6, mouse_move, &g);
    mlx_hook(g.wind, 2, 1L<<0, keypress, &g);
	mlx_hook(g.wind, 17, 1L<<17, closewind, &g);
    mlx_loop_hook(g.mlx, render, &g);
    show_control();
	mlx_loop(g.mlx);
}
