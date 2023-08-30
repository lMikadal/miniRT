/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:50:30 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:50:31 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v3d_dot(t_v3d a, t_v3d b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_v3d	v3d_cross(t_v3d a, t_v3d b)
{
	t_v3d	v;

	v.x = (a.y * b.z) - (a.z * b.y);
	v.y = (a.z * b.x) - (a.x * b.z);
	v.z = (a.x * b.y) - (a.y * b.x);
	return (v);
}

t_v3d	v3d_unit_vec(t_v3d a)
{
	t_v3d	v;
	double	len;

	len = v3d_length(a);
	v.x = a.x / len;
	v.y = a.y / len;
	v.z = a.z / len;
	return (v);
}
