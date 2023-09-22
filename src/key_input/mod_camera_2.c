/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_camera_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:26:37 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 13:39:55 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_yaw_right(t_camera *cam)
{
	t_v2d	rot;

	rot = v2d_create(cam->normalized_vector.x, cam->normalized_vector.z);
	rot = v2d_rotate(rot, 30.0);
	cam->normalized_vector.x = rot.x;
	cam->normalized_vector.z = rot.y;
	cam->normalized_vector = v3d_unit_vec(cam->normalized_vector);
}

void	cam_yaw_left(t_camera *cam)
{
	t_v2d	rot;

	rot = v2d_create(cam->normalized_vector.x, cam->normalized_vector.z);
	rot = v2d_rotate(rot, -30.0);
	cam->normalized_vector.x = rot.x;
	cam->normalized_vector.z = rot.y;
	cam->normalized_vector = v3d_unit_vec(cam->normalized_vector);
}

static void	cam_rotate_updown(t_camera *cam, double angle)
{
	t_v2d	rot;

	rot = v2d_create(cam->normalized_vector.z, cam->normalized_vector.y);
	rot = v2d_rotate(rot, angle);
	cam->normalized_vector.z = rot.x;
	cam->normalized_vector.y = rot.y;
	cam->normalized_vector = v3d_unit_vec(cam->normalized_vector);
}

void	rotatecam_updown(int key, t_camera *cam)
{
	if (cam->normalized_vector.x != 0)
		return ;
	if (key == KEY_ARR_UP && cam->normalized_vector.y != 1)
		cam_rotate_updown(cam, 30);
	else if (key == KEY_ARR_DOWN && cam->normalized_vector.y != -1)
		cam_rotate_updown(cam, -30);
}

void	reset_camera(t_camera *cam)
{
	cam->normalized_vector = v3d_create(0, 0, 1);
	cam->fov = 90.0;
}
