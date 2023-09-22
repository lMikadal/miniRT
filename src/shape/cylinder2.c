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

int	h_c(double t, t_cylinder *cy, \
			t_hit_record *rec, double denom)
{
	rec->type = CY;
	rec->normal = cy->normalized_vector;
	if (denom > 0)
		rec->normal = v3d_mult_double(rec->normal, -1);
	rec->normal = v3d_unit_vec(rec->normal);
	return (set_rec(rec, t, cy->color));
}

t_v3d	find_t_dot(double dot, t_cylinder *cy, t_v3d tb[])
{
	if (dot >= cy->height / 2)
		return (tb[0]);
	return (tb[1]);
}

int	check_top_bottom(double t_t, double t_b, int *flag, double *t)
{
	*t = INFINITY;
	if (flag[0] && flag[1])
	{
		if (t_t < t_b)
			*t = t_t;
		else
			*t = t_b;
	}
	else if (flag[0])
		*t = t_t;
	else if (flag[1])
		*t = t_b;
	if (*t != INFINITY)
		return (T);
	return (F);
}

int	set_cap_top_bottom(t_ray r, double t, t_v3d cap, t_cylinder *cy)
{
	t_v3d	v;

	v = v3d_opr_minus(ray_at(r, t), cap);
	if (sqrtf(v3d_dot(v, v)) <= cy->radius)
		return (T);
	return (F);
}
