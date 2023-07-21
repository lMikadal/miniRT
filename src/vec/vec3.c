/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:26:43 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/02 16:28:28 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_v3d v3d_create(double x, double y, double z)
{
	t_v3d v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double v3d_length_squared(t_v3d v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double v3d_length(t_v3d v)
{
	return (sqrt(v3d_length_squared(v)));
}

t_v3d v3d_normalize(t_v3d v)
{
	double len;
	double invlen;

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

double v3d_dot(t_v3d a, t_v3d b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_v3d v3d_cross(t_v3d a, t_v3d b)
{
	t_v3d v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

t_v3d v3d_opr_plus(t_v3d a, t_v3d b)
{
	t_v3d v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_v3d v3d_opr_minus(t_v3d a, t_v3d b)
{
	t_v3d v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_v3d v3d_opr_mult(t_v3d a, t_v3d b)
{
	t_v3d v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	return (v);
}

t_v3d v3d_opr_div(t_v3d a, t_v3d b)
{
	t_v3d v;

	v.x = a.x / b.x;
	v.y = a.y / b.y;
	v.z = a.z / b.z;
	return (v);
}

t_v3d v3d_mult_minus(t_v3d a)
{
	t_v3d v;

	v.x = a.x * -1;
	v.y = a.y * -1;
	v.z = a.z * -1;
	return (v);
}

void v3d_add2(t_v3d *a, t_v3d b)
{
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
}

void v3d_mult2(t_v3d *a, t_v3d b)
{
	a->x *= b.x;
	a->y *= b.y;
	a->z *= b.z;
}

void v3d_div2(t_v3d *a, double b)
{
	a->x /= b;
	a->y /= b;
	a->z /= b;
}

t_v3d v3d_mult_double(t_v3d a, double b)
{
	t_v3d v;

	v.x = a.x * b;
	v.y = a.y * b;
	v.z = a.z * b;
	return (v);
}

t_v3d v3d_unit_vec(t_v3d a)
{
	t_v3d v;
	double len;

	len = v3d_length(a);
	v.x = a.x / len;
	v.y = a.y / len;
	v.z = a.z / len;
	return (v);
}
