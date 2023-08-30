#include "minirt.h"

// write pixel
void ft_mlx_pixel_put(t_mlx *ptr, int x, int y, int color)
{
	char *dst;

	dst = ptr->addr + ((y * ptr->line) + (x * (ptr->bits / 8)));
	*(unsigned int *)dst = color;
}

int ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	exit(0);
	return (0);
}

int ft_key_hook(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_close(mlx);
	return (0);
}

void ft_write_map(char *name, t_info *info)
{
	t_mlx mlx;

	// create window of put image
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, HORIZON, VERTICAL, name);
	// create image
	mlx.img = mlx_new_image(mlx.mlx, HORIZON, VERTICAL);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits, &mlx.line, &mlx.endian);

	mlx.info = info;
	render(&mlx);

	// push image to window
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	// close window
	mlx_key_hook(mlx.mlx_win, ft_key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, ft_close, &mlx);
	// loop image show
	mlx_loop(mlx.mlx);
}