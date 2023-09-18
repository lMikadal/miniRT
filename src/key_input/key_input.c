/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 04:02:21 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/18 15:31:34 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// not cx n and esc
int	cx_validkey(int key)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		return (1);
	else if (key == KEY_Q || key == KEY_E || key == KEY_L_BRAC || key == KEY_R_BRAC)
		return (1);
	else if (key == KEY_Z || key == KEY_X || key == KEY_C || key == KEY_V)
		return (1);
	else if (key == KEY_ARR_UP || key == KEY_ARR_LEFT)
		return (1);
	else if (key == KEY_ARR_DOWN || key == KEY_ARR_RIGHT)
		return (1);
	else if (key == KEY_R)
		return (1);
	return (0);
}	

void	err_key(int mode)
{
	if (mode == 1)
		printf("Invalid key\n");
	else if (mode == 2)
		printf("Invalid key for selected object\n");
}

// mode 1 print current object
void	what_shape(t_ptr2obj *ptr2obj)
{
	printf("Current object = ");
	if (ptr2obj->count == 1)
		printf("camera\n");
	else if (ptr2obj->count == 2)
		printf("light\n");
	else if (ptr2obj->count == 3)
		printf("ambient\n");
	else if (ptr2obj->count == 4)
	{
		printf("shape = ");
		if (ptr2obj->hitlist->type == SP)
			printf("sphere\n");
		else if (ptr2obj->hitlist->type == PL)
			printf("plane\n");
		else if (ptr2obj->hitlist->type == CY)
			printf("cylinder\n");
	}
}

void	select_nextobj(t_mlx *mlx)
{
	if (mlx->ptr2obj->count == 4)
	{
		mlx->ptr2obj->hitlist = mlx->ptr2obj->hitlist->next;
		if (mlx->ptr2obj->hitlist == NULL)
		{	
			mlx->ptr2obj->hitlist = mlx->info->hittable_list;
			mlx->ptr2obj->count = 1;
		}
	}
	else
		mlx->ptr2obj->count++;
	what_shape(mlx->ptr2obj);
}

void	to_shape(int key, t_ptr2obj *ptr2obj, int *stat)
{
	if (ptr2obj->hitlist->type == SP)
		*stat = to_sphere(key, ptr2obj->hitlist->sphere);
	// else if (ptr2obj->hitlist->type == PL)
	// 	*stat = to_plane(key, ptr2obj->hitlist->plane, stat);
	// else if (ptr2obj->hitlist->type == CY)
	// 	*stat = to_cylinder(key, ptr2obj->hitlist->cylinder, stat);
}

void	to_keyhall(int key, t_mlx *mlx)
{
	int	stat;

	stat = 1;
	if (mlx->ptr2obj->count == 1)
		to_camera(key, mlx->ptr2obj, &stat);
	else if (mlx->ptr2obj->count == 2)
		to_light(key, mlx->ptr2obj->light, &stat);
	else if (mlx->ptr2obj->count == 3)
		to_ambient(key, mlx->ptr2obj->ambient, &stat);
	else if (mlx->ptr2obj->count == 4)
		to_shape(key, mlx->ptr2obj, &stat);
	if (stat)
		to_re_render(mlx);
}
