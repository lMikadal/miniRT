/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:11:56 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 14:05:47 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	pl_yaw_left(t_plane *pl)
{
	t_v2d rot;

	rot = v2d_create(pl->normalized_vector.x, pl->normalized_vector.z);
	rot = v2d_rotate(rot, -30.0);
	pl->normalized_vector.x = rot.x;
	pl->normalized_vector.z = rot.y;
	pl->normalized_vector = v3d_unit_vec(pl->normalized_vector);
}

static void	pl_yaw_right(t_plane *pl)
{
	t_v2d rot;

	rot = v2d_create(pl->normalized_vector.x, pl->normalized_vector.z);
	rot = v2d_rotate(rot, 30.0);
	pl->normalized_vector.x = rot.x;
	pl->normalized_vector.z = rot.y;
	pl->normalized_vector = v3d_unit_vec(pl->normalized_vector);
}

static void	pl_rotate_updown(t_plane *pl, double angle)
{
	t_v2d	rot;

	rot = v2d_create(pl->normalized_vector.z, pl->normalized_vector.y);
	rot = v2d_rotate(rot, angle);
	pl->normalized_vector.z = rot.x;
	pl->normalized_vector.y = rot.y;
	pl->normalized_vector = v3d_unit_vec(pl->normalized_vector);
}

static void	rotatepl_updown(int key, t_plane *pl)
{
	if (pl->normalized_vector.y != 0)
		return ;
	if (key == KEY_ARR_UP && pl->normalized_vector.z != 1)
		pl_rotate_updown(pl, 30);
	else if (key == KEY_ARR_DOWN && pl->normalized_vector.z != -1)
		pl_rotate_updown(pl, -30);
}

static void	pl_rotate(int key, t_plane *pl)
{
	if (key == KEY_ARR_UP || key == KEY_ARR_DOWN)
		rotatepl_updown(key, pl);
	else if (key == KEY_ARR_LEFT || key == KEY_ARR_RIGHT)
	{
		if (key == KEY_ARR_LEFT)
			pl_yaw_left(pl);
		else if (key == KEY_ARR_RIGHT)
			pl_yaw_right(pl);
	}
}

int	to_plane(int key, t_plane *pl)
{
	if (key == KEY_Q)
		pl->coordinates_point.y += 0.2;
	else if (key == KEY_E)
		pl->coordinates_point.y -= 0.2;
	else if (key == KEY_ARR_UP || key == KEY_ARR_DOWN
	|| key == KEY_ARR_LEFT || key == KEY_ARR_RIGHT)
		pl_rotate(key, pl);
	else if (key == KEY_R)
		pl->normalized_vector = v3d_unit_vec(v3d_create(0, 1, 0));


	return (1);
}
