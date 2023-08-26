/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:33:14 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:33:16 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mlx_pixel_put(t_mlx *ptr, int x, int y, int color)
{
	char	*dst;

	dst = ptr->addr + ((y * ptr->line) + (x * (ptr->bits / 8)));
	*(unsigned int *)dst = color;
}

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	exit(0);
	return (0);
}

int	ft_key_hook(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_close(mlx);
	return (0);
}

void	ft_write_map(char *name, t_info *info)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, HORIZON, VERTICAL, name);
	mlx.img = mlx_new_image(mlx.mlx, HORIZON, VERTICAL);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits, &mlx.line, &mlx.endian);
	render(&mlx, info);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, ft_key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, ft_close, &mlx);
	mlx_loop(mlx.mlx);
}
