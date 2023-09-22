/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:27:53 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 11:56:01 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	move_cam_pos(int key, t_camera *cam)
{
	if (key == KEY_W)
		cam->coordinates_point.z += 0.2;
	else if (key == KEY_A)
		cam->coordinates_point.x += 0.2;
	else if (key == KEY_S)
		cam->coordinates_point.z -= 0.2;
	else if (key == KEY_D)
		cam->coordinates_point.x -= 0.2;
	else if (key == KEY_Q)
		cam->coordinates_point.y += 0.2;
	else if (key == KEY_E)
		cam->coordinates_point.y -= 0.2;
}

static void	wide_cam(int key, t_camera *cam)
{
	if (key == KEY_Z)
		cam->fov += 10.0;
	else if (key == KEY_X)
		cam->fov -= 10.0;
	if (cam->fov <= 0.0)
		cam->fov = 10.0;
	else if (cam->fov > 170.0)
		cam->fov = 170.0;
}

static void	rotate_cam(int key, t_ptr2obj *ptr)
{
	if (key == KEY_ARR_UP || key == KEY_ARR_DOWN)
		rotatecam_updown(key, ptr->camera);
	else if (key == KEY_ARR_LEFT || key == KEY_ARR_RIGHT)
	{
		if (key == KEY_ARR_LEFT)
			cam_yaw_left(ptr->camera);
		else if (key == KEY_ARR_RIGHT)
			cam_yaw_right(ptr->camera);
	}
}

void	to_camera(int key, t_ptr2obj *ptr2obj, int *stat)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D 
		|| key == KEY_Q || key == KEY_E)
		move_cam_pos(key, ptr2obj->camera);
	else if (key == KEY_ARR_UP || key == KEY_ARR_LEFT || key == KEY_ARR_DOWN 
		|| key == KEY_ARR_RIGHT)
		rotate_cam(key, ptr2obj);
	else if (key == KEY_Z || key == KEY_X)
		wide_cam(key, ptr2obj->camera);
	else if (key == KEY_R)
		reset_camera(ptr2obj->camera);
}

