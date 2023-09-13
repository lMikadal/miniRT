/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:26:43 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/03 08:35:11 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	v3d_create(double x, double y, double z)
{
	t_v3d	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_v3d	v3d_mult_minus(t_v3d a)
{
	t_v3d	v;

	v.x = a.x * -1;
	v.y = a.y * -1;
	v.z = a.z * -1;
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

t_v3d	v3d_opr_mult(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	return (v);
}

t_v3d	v3d_opr_div(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.x / b.x;
	v.y = a.y / b.y;
	v.z = a.z / b.z;
	return (v);
}
