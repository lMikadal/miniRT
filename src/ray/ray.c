/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:57:37 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/01 23:10:50 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_create(t_v3d o, t_v3d d)
{
	t_ray	r;

	r.orig = v3d_create(o.x, o.y, o.z);
	r.dir = v3d_create(d.x, d.y, d.z);
	return (r);
}

t_v3d	ray_at(t_ray r, double t)
{
	return (v3d_opr_plus(r.orig, v3d_mult_double(r.dir, t)));
}
