#include "../include/cub3d.h"

int main()
{
	t_game g;
	ft_memset(&g, 0, sizeof(t_game));
	init(&g);
	config(&g);
}

void config(t_game *g)
{
	mlx_hook(g->wind, MotionNotify, PointerMotionMask, mouse, g);
	mlx_hook(g->wind, KeyPress, KeyPressMask, keyboard, g);
	mlx_hook(g->wind, DestroyNotify, StructureNotifyMask, closewind, g);
	mlx_loop_hook(g->mlx, render, g);
	mlx_loop(g->mlx);
}

int closewind(t_game *g)
{
	if (g->display)
		mlx_destroy_image(g->mlx, g->display);
	mlx_destroy_window(g->mlx, g->wind);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}