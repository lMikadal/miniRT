/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:37:49 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 00:37:51 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v3d_length_squared(t_v3d v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

double	v3d_length(t_v3d v)
{
	return (sqrt(v3d_length_squared(v)));
}

t_v3d	v3d_opr_minus(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_v3d	v3d_mult_double(t_v3d a, double b)
{
	t_v3d	v;

	v.x = a.x * b;
	v.y = a.y * b;
	v.z = a.z * b;
	return (v);
}

t_v3d	v3d_div_double(t_v3d a, double b)
{
	t_v3d	v;

	v.x = a.x / b;
	v.y = a.y / b;
	v.z = a.z / b;
	return (v);
}
