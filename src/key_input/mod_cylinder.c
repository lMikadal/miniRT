/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:21:29 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 13:50:22 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cy_move(int key, t_cylinder *cy)
{
	if (key == KEY_W)
		cy->coordinates_center.z += 0.2;
	else if (key == KEY_A)
		cy->coordinates_center.x += 0.2;
	else if (key == KEY_S)
		cy->coordinates_center.z -= 0.2;
	else if (key == KEY_D)
		cy->coordinates_center.x -= 0.2;
}

static	void	cy_radius(int key, t_cylinder *cy)
{
	if (key == KEY_L_BRAC)
		cy->radius += 0.2;
	else if (key == KEY_R_BRAC)
		cy->radius -= 0.2;
}

static void	cy_height(int key, t_cylinder *cy)
{
	if (key == KEY_Z)
		cy->height += 0.2;
	else if (key == KEY_X)
		cy->height -= 0.2;
}

int	to_cylinder(int key, t_cylinder *cy)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		cy_move(key, cy);
	else if (key == KEY_Q || key == KEY_E)
	{
		if (key == KEY_Q)
			cy->coordinates_center.y += 0.2;
		else if (key == KEY_E)
			cy->coordinates_center.y -= 0.2;
	}
	else if (key == KEY_L_BRAC || key == KEY_R_BRAC)
		cy_radius(key, cy);
	else if (key == KEY_Z || key == KEY_X)
		cy_height(key, cy);
	else if (key == KEY_ARR_UP || key == KEY_ARR_LEFT
		|| key == KEY_ARR_DOWN || key == KEY_ARR_RIGHT)
		cy_rotate(key, cy);
	else if (key == KEY_R)
		cy->normalized_vector = v3d_create(0, 1, 0);
	else
		return (0);
	return (1);
}
