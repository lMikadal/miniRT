/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:15:12 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/18 15:24:18 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	to_sphere(int key, t_sphere *sp)
{
	if (key == KEY_W)
		sp->coordinates_center.z += 0.2;
	else if (key == KEY_A)
		sp->coordinates_center.x += 0.2;
	else if (key == KEY_S)
		sp->coordinates_center.z -= 0.2;
	else if (key == KEY_D)
		sp->coordinates_center.x -= 0.2;
	else if (key == KEY_Q)
		sp->coordinates_center.y += 0.2;
	else if (key == KEY_E)
		sp->coordinates_center.y -= 0.2;
	else if (key == KEY_Z)
		sp->radius += 0.2;
	else if (key == KEY_X)
		sp->radius -= 0.2;
	else
		return (0);
	if (sp->radius <= 0.0)
	{
		sp->radius = 0.2;
		return (0);
	}
	return (1);
}
