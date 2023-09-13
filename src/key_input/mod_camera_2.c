/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_camera_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:26:37 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/02 00:54:27 by pruangde         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minirt.h"

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
