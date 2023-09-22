/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cylinder_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:23:29 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 13:44:04 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cy_yaw_right(t_cylinder *cy)
{
	t_v2d rot;

	rot = v2d_create(cy->normalized_vector.x, cy->normalized_vector.z);
	rot = v2d_rotate(rot, 30.0);
	cy->normalized_vector.x = rot.x;
	cy->normalized_vector.z = rot.y;
	cy->normalized_vector = v3d_unit_vec(cy->normalized_vector);
}

static void	cy_yaw_left(t_cylinder *cy)
{
	t_v2d rot;

	rot = v2d_create(cy->normalized_vector.x, cy->normalized_vector.z);
	rot = v2d_rotate(rot, -30.0);
	cy->normalized_vector.x = rot.x;
	cy->normalized_vector.z = rot.y;
	cy->normalized_vector = v3d_unit_vec(cy->normalized_vector);
}

static void	cy_rotate_updown(t_cylinder *cy, double angle)
{
	t_v2d	rot;

	rot = v2d_create(cy->normalized_vector.z, cy->normalized_vector.y);
	rot = v2d_rotate(rot, angle);
	cy->normalized_vector.z = rot.x;
	cy->normalized_vector.y = rot.y;
	cy->normalized_vector = v3d_unit_vec(cy->normalized_vector);
}

static void	rotatecy_updown(int key, t_cylinder *cy)
{
	if (cy->normalized_vector.x != 0)
		return ;
	if (key == KEY_ARR_UP && cy->normalized_vector.y != 1)
		cy_rotate_updown(cy, 30);
	else if (key == KEY_ARR_DOWN && cy->normalized_vector.y != -1)
		cy_rotate_updown(cy, -30);
}

void	cy_rotate(int key, t_cylinder *cy)
{
	if (key == KEY_ARR_UP || key == KEY_ARR_DOWN)
		rotatecy_updown(key, cy);
	else if (key == KEY_ARR_LEFT || key == KEY_ARR_RIGHT)
	{
		if (key == KEY_ARR_LEFT)
			cy_yaw_left(cy);
		else if (key == KEY_ARR_RIGHT)
			cy_yaw_right(cy);
	}
}
