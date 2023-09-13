/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:33:14 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/03 02:52:39 by pruangde         ###   ########.fr       */
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
	if (key == KEY_ESC)
		ft_close(mlx);
	else if (key == KEY_N)
		select_nextobj(mlx);
	else if (cx_validkey(key))
		to_keyhall(key, mlx);
	else
		err_key(1);
	return (0);
}

void	init_ptr2obj(t_info *info, t_ptr2obj *ptr2obj)
{
	ptr2obj->count = 1;
	ptr2obj->camera = info->camera;
	ptr2obj->light = info->light;
	ptr2obj->ambient = info->ambient;
	ptr2obj->hitlist = info->hittable_list;
	ptr2obj->prev_cam = v3d_create(0, 0, 0);

	printf("Key Instruction\n\n");
	printf("WASD  : move selected object\n");
	printf("Q/E   : move selected object up/down\n");
	printf("Arrows: rotate selected object pitch/yaw\n");
	printf("[ or ]: rotate selected object roll\n");
	printf("Z/X   : increase/decrease selected object size\n");
	printf("C/V   : increase/decrease selected object height\n");
	printf("N     : select next object\n\n");
}

void	ft_write_map(char *name, t_info *info)
{
	t_mlx		mlx;
	t_ptr2obj	ptr2obj;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, HORIZON, VERTICAL, name);
	mlx.img = mlx_new_image(mlx.mlx, HORIZON, VERTICAL);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits, &mlx.line, &mlx.endian);

	mlx.info = info;
	init_ptr2obj(info, &ptr2obj);
	mlx.ptr2obj = &ptr2obj;
	what_shape(mlx.ptr2obj);
	render(&mlx);

	// push image to window
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, ft_key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, ft_close, &mlx);
	mlx_loop(mlx.mlx);
}
