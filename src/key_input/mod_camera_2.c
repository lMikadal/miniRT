/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_camera_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:26:37 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/18 15:49:11 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// norm direction to x and z value


void	cam_yaw_right(t_camera *cam)
{
	if (cam->normalized_vector.x == 1.0)
	{
		if (cam->normalized_vector.z == 1.0)
			cam->normalized_vector.x = 0.0;
		else if (cam->normalized_vector.z == 0.0)
			cam->normalized_vector.z = 1.0;
		else if (cam->normalized_vector.z == -1.0)
			cam->normalized_vector.z = 0.0;
	}
	if (cam->normalized_vector.x == 0.0)
	{
		if (cam->normalized_vector.z == 1.0)
			cam->normalized_vector.x = -1.0;
		else if (cam->normalized_vector.z == -1.0)
			cam->normalized_vector.x = 1.0;
	}
	if (cam->normalized_vector.x == -1.0)
	{
		if (cam->normalized_vector.z == 1.0)
			cam->normalized_vector.z = 0.0;
		else if (cam->normalized_vector.z == 0.0)
			cam->normalized_vector.z = -1.0;
		else if (cam->normalized_vector.z == -1.0)
			cam->normalized_vector.x = 0.0;
	}
}

void	cam_yaw_left(t_camera *cam)
{
	if (cam->normalized_vector.x == 1.0)
	{
		if (cam->normalized_vector.z == 1.0)
			cam->normalized_vector.z = 0.0;
		else if (cam->normalized_vector.z == 0.0)
			cam->normalized_vector.z = -1.0;
		else if (cam->normalized_vector.z == -1.0)
			cam->normalized_vector.x = 0.0;
	}
	if (cam->normalized_vector.x == 0.0)
	{
		if (cam->normalized_vector.z == 1.0)
			cam->normalized_vector.x = 1.0;
		else if (cam->normalized_vector.z == -1.0)
			cam->normalized_vector.x = -1.0;
	}
	if (cam->normalized_vector.x == -1.0)
	{
		if (cam->normalized_vector.z == 1.0)
			cam->normalized_vector.x = 0.0;
		else if (cam->normalized_vector.z == 0.0)
			cam->normalized_vector.z = 1.0;
		else if (cam->normalized_vector.z == -1.0)
			cam->normalized_vector.z = 0.0;
	}
}

void	reset_camera(t_camera *cam, int *stat)
{
	cam->normalized_vector = v3d_create(0, 0, 1);
	cam->fov = 90.0;
}
