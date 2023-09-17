/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:13:46 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/17 05:04:29 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_v3d	reflect(t_v3d v, t_v3d n)
{
	return (v3d_opr_minus(v, v3d_mult_double(n, 2 * v3d_dot(v, n))));
}

int	sphere(t_ray r, double t_max, t_hit_record *rec, t_sphere *sp)
{
	t_v3d	oc;
	double	ob[3];
	double	dis;
	double	sqrtd;
	double	t;

	oc = v3d_opr_minus(r.orig, sp->coordinates_center);
	ob[0] = v3d_dot(r.dir, r.dir);
	ob[1] = 2.0 * v3d_dot(oc, r.dir);
	ob[2] = v3d_dot(oc, oc) - (sp->radius * sp->radius);
	dis = (ob[1] * ob[1]) - (4 * ob[0] * ob[2]);
	if (dis < 0)
		return (F);
	sqrtd = sqrt(dis);
	t = ((ob[1] * -1) - sqrtd) / (2.0 * ob[0]);
	if (t <= MIN || t_max <= t)
	{
		t = ((ob[1] * -1) + sqrtd) / (2.0 * ob[0]);
		if (t <= MIN || t_max <= t)
			return (F);
	}
	rec->type = SP;
	rec->p = ray_at(r, t);
	// rec->p = v3d_unit_vec(rec->p);
	rec->normal = v3d_opr_minus(rec->p, sp->coordinates_center);

	// rec->normal = v3d_div_double(v3d_opr_minus(rec->p, sp->coordinates_center), sp->radius);
	// if (v3d_dot(r.dir, rec->normal) > 0)
	// 	rec->normal = v3d_mult_double(rec->normal, -1);

	t_v3d ref = reflect(v3d_unit_vec(r.dir), rec->normal);
	
	return (set_rec(rec, t, sp->color));
}
