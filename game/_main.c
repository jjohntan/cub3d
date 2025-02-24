/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:38:34 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/24 22:01:29 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

static void	check_file_extension(char *av)
{
	int	len;
	
	len = ft_strlen(av) - 4;
	if (len < 4 || ft_strncmp(&av[len], ".cub", 4) != 0)
		error_exit("Error\nInvalid extension");
}

static void	init(int ac, char **av, t_game *data)
{
	if (ac != 2)
		error_exit("Error\nInvalid number of argument");
	ft_memset(data, 0, sizeof(t_game));
	check_file_extension(av[1]);
	parser(av[1], data);
	valid_texture(data);
	valid_color(data);
	valid_map(data);
	data->mlx = mlx_init();
	data->wind = mlx_new_window(data->mlx, WIND_W, WIND_H, "Cub3D");
	data->p1.dx = cos(data->p1.angle);
	data->p1.dy = sin(data->p1.angle);
	init_asset(data);
	init_minimap(data);
}

void	show_control(void)
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

int	main(int ac, char **av)
{
	t_game	g;

	init(ac, av, &g);
	mlx_hook(g.wind, 4, 1L << 2, mouse_down, &g);
	mlx_hook(g.wind, 5, 1L << 3, mouse_up, &g);
	mlx_hook(g.wind, 6, 1L << 6, mouse_move, &g);
	mlx_hook(g.wind, 2, 1L << 0, keypress, &g);
	mlx_hook(g.wind, 17, 1L << 17, closewind, &g);
	mlx_loop_hook(g.mlx, render, &g);
	show_control();
	mlx_loop(g.mlx);
}
