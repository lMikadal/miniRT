/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:28:37 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 00:28:39 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere(t_ray r, double t_max, t_hit_record *rec, t_sphere *sp)
{
	t_v3d oc;
	double ob[3];
	double dis;
	double sqrtd;
	double t;

	oc = v3d_opr_minus(r.orig, sp->coordinates_center);
	ob[0] = v3d_dot(r.dir, r.dir);
	ob[1] = 2.0 * v3d_dot(oc, r.dir);
	ob[2] = v3d_dot(oc, oc) - (sp->radius * sp->radius);
	dis = (ob[1] * ob[1]) - (4 * ob[0] * ob[2]);
	if (dis < 0)
		return (F);
	sqrtd = sqrt(dis);
	t = ((ob[1] * -1) - sqrtd) / (2.0 * ob[0]);
	if (t < MIN || t_max <= t)
	{
		t = ((ob[1] * -1) + sqrtd) / (2.0 * ob[0]);
		if (t < MIN || t_max <= t)
			return (F);
	}
	return (set_rec(rec, t, sp->color));
}
