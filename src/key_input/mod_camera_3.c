/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_camera_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:46:02 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/04 05:17:24 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 = are 0.0
int	normal_vec_zx_zero(t_v3d cam)
{
	if (cam.x == 0.0 && cam.z == 0.0)
		return (1);
	return (0);
}

// cx if y value exceed 1 
static void	cx_normalize_camy(t_v3d *v, int *stat)
{
	if (v->y > 1.0)
	{
		v->y = 1.0;
		*stat = 0;
	}
	else if (v->y < -1.0)
	{
		v->y = -1.0;
		*stat = 0;
	}
}

void	rotatecam_updown(int key, t_ptr2obj *ptr, int *stat)
{
	if (normal_vec_zx_zero(ptr->camera->normalized_vector) )
	{

		if ((key == KEY_ARR_UP && ptr->camera->normalized_vector.y == -1.0) 
			|| (key == KEY_ARR_DOWN && ptr->camera->normalized_vector.y == 1.0))
		{
			if (v3d_cmp(ptr->prev_cam, v3d_create(0, 0, 0)))
				ptr->camera->normalized_vector.z = 1.0;
			else
			{
				ptr->camera->normalized_vector.z = ptr->prev_cam.z;
				ptr->camera->normalized_vector.x = ptr->prev_cam.x;
				if (key == KEY_ARR_UP)
					ptr->camera->normalized_vector.y -= 1.0;
				else if (key == KEY_ARR_DOWN)
					ptr->camera->normalized_vector.y += 1.0;
			}	
		}
	}
	else if (ptr->camera->normalized_vector.y > 0.8 || ptr->camera->normalized_vector.y < -0.8)
	{
		// fix this 
		ptr->camera->normalized_vector.x = 0.0;
		ptr->camera->normalized_vector.z = 0.0;
	}
	if (key == KEY_ARR_UP)
		ptr->camera->normalized_vector.y += 1.0;
	else if (key == KEY_ARR_DOWN)
		ptr->camera->normalized_vector.y -= 1.0;
	cx_normalize_camy(&ptr->camera->normalized_vector, stat);
}

