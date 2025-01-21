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

int closewind(t_game *d)
{
	if (d->display)
		mlx_destroy_image(d->mlx, d->display);
	mlx_destroy_window(d->mlx, d->wind);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}