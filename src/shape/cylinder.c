/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:24:10 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/14 16:31:46 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	find_top_bottom(t_v3d *tb, t_cylinder *cy)
{
	t_v3d	half_h;

	half_h = v3d_mult_double(cy->normalized_vector, cy->height / 2);
	tb[0] = v3d_opr_plus(cy->coordinates_center, half_h);
	tb[1] = v3d_opr_minus(cy->coordinates_center, half_h);
	return (1);
}

int	hit_cap(t_cylinder *cy, t_ray r, double *dot, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_v3d	tb[2];
	t_v3d	v;

	denom = v3d_dot(cy->normalized_vector, r.dir);
	if (fabs(denom) >= MIN && find_top_bottom(tb, cy))
	{
		if (dot[0] >= cy->height / 2)
			t = v3d_dot(v3d_opr_minus(tb[0], r.orig), \
				cy->normalized_vector) / denom;
		else if (dot[0] < (cy->height * -1) / 2)
			t = v3d_dot(v3d_opr_minus(tb[1], r.orig), \
				cy->normalized_vector) / denom;
		if (t > MIN && t < dot[1])
		{
			v = v3d_opr_minus(ray_at(r, t), find_t_dot(dot[0], cy, tb));
			if (sqrtf(v3d_dot(v, v)) <= cy->radius)
			{
				rec->p = ray_at(r, t);
				return (h_c(t, cy, rec, denom));
			}
		}
	}
	return (F);
}

int	hit_body(t_ray r, double t, t_cylinder *cy, double *dot)
{
	t_v3d	point;
	t_v3d	ori_diff;

	point = ray_at(r, t);
	ori_diff = v3d_opr_minus(point, cy->coordinates_center);
	*dot = v3d_dot(ori_diff, cy->normalized_vector);
	if (fabs(*dot) >= cy->height / 2)
		return (F);
	return (T);
}

double	set_cy_t(t_ray r, t_cylinder *cy, t_v3d oc)
{
	double	data[3];
	double	discrim;
	double	t[3];

	data[0] = v3d_dot(r.dir, r.dir) - \
		pow(v3d_dot(r.dir, cy->normalized_vector), 2);
	data[1] = (v3d_dot(r.dir, oc) - v3d_dot(r.dir, cy->normalized_vector) \
		* v3d_dot(oc, cy->normalized_vector));
	data[2] = v3d_dot(oc, oc) - pow(v3d_dot(oc, cy->normalized_vector), 2) \
		- (cy->radius * cy->radius);
	discrim = (data[1] * data[1]) - (data[0] * data[2]);
	if (discrim < 0)
		return (F);
	t[1] = ((data[1] * -1) - sqrt(discrim)) / data[0];
	t[2] = ((data[1] * -1) + sqrt(discrim)) / data[0];
	t[0] = t[1];
	if (t[1] > t[2])
		t[0] = t[2];
	return (t[0]);
}

int	cylinder(t_ray r, double t_max, t_hit_record *rec, t_cylinder *cy)
{
	t_v3d	oc;
	double	t;
	double	dot[2];
	double	tmp[2];

	oc = v3d_opr_minus(r.orig, cy->coordinates_center);
	t = set_cy_t(r, cy, oc);
	if (t > MIN && t < t_max && hit_body(r, t, cy, &dot[0]) != F)
	{
		rec->type = CY;
		rec->p = ray_at(r, t);
		tmp[0] = v3d_dot(cy->normalized_vector, r.dir) * t;
		tmp[1] = v3d_dot(cy->normalized_vector, oc);
		rec->normal = v3d_unit_vec(v3d_opr_minus(\
			v3d_opr_minus(rec->p, cy->coordinates_center), \
			v3d_mult_double(cy->normalized_vector, tmp[0] + tmp[1])));
		return (set_rec(rec, t, cy->color));
	}
	dot[1] = t_max;
	return (hit_cap(cy, r, dot, rec));
}
