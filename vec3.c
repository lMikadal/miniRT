/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:26:43 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/01 14:30:46 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	v3d_create(t_v3d *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

double	v3d_length(t_v3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_v3d	v3d_normalize(t_v3d v)
{
	double	len;
	double	invlen;
	t_v3d	ret;

	len = v3d_length(v);
	if (len > 0)
	{
		invlen = 1 / len;
		v.x *= invlen;
		v.y *= invlen;
		v.z *= invlen;
	}
	return (v);
}

double	v3d_dot(t_v3d *a, t_v3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_v3d	v3d_cross(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

t_v3d	v3d_opr_plus(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_v3d	v3d_opr_minus(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_v3d	v3d_opr_mult(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	return (v);
}


