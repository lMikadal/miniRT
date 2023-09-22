/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 07:59:14 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 16:26:32 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	to_light(int key, t_light *lgt)
{
	if (key == KEY_W)
		lgt->coordinates_point.z += 0.2;
	else if (key == KEY_A)
		lgt->coordinates_point.x += 0.2;
	else if (key == KEY_S)
		lgt->coordinates_point.z -= 0.2;
	else if (key == KEY_D)
		lgt->coordinates_point.x -= 0.2;
	else if (key == KEY_Q)
		lgt->coordinates_point.y += 0.2;
	else if (key == KEY_E)
		lgt->coordinates_point.y -= 0.2;
	else if (key == KEY_Z)
		lgt->ratio += 0.2;
	else if (key == KEY_X)
		lgt->ratio -= 0.2;
	else
	{
		err_key(2);
		return ;
	}
	if (lgt->ratio < 0.0)
		lgt->ratio = 0.0;
	else if (lgt->ratio > 1.0)
		lgt->ratio = 1.0;
}

void	to_ambient(int key, t_ambient *amb)
{
	if (key == KEY_Z)
		amb->ratio += 0.2;
	else if (key == KEY_X)
		amb->ratio -= 0.2;
	else
	{
		err_key(2);
		return ;
	}
	if (amb->ratio < 0.0)
		amb->ratio = 0.0;
	else if (amb->ratio > 1.0)
		amb->ratio = 1.0;
}
