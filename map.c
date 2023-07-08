/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:30:43 by pmikada           #+#    #+#             */
/*   Updated: 2023/07/02 13:49:02 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// write pixel
void	ft_mlx_pixel_put(t_mlx *ptr, int x, int y, int color)
{
	char	*dst;

	dst = ptr->addr + ((y * ptr->line) + (x * (ptr->bits / 8)));
	*(unsigned int *)dst = color;
}

static void	ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	exit (0);
}

static void	ft_key_hook(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_close(mlx);
}

void	ft_write_map(char *name, t_info *info)
{
	t_mlx	mlx;

    // create window of put image
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, HORIZON, VERTICAL, name);
    // create image
	mlx.img = mlx_new_image(mlx.mlx, HORIZON, VERTICAL);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits, &mlx.line, &mlx.endian);
    
	render(&mlx, info);
	// push image to window
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	// close window
	mlx_key_hook(mlx.mlx_win, ft_key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, ft_close, &mlx);
    // loop image show
	mlx_loop(mlx.mlx);
}
