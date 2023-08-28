/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:06:15 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:06:17 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	plane(t_ray r, double t_max, t_hit_record *rec, t_plane *pl)
{
	double	t;
	double	denom;

	denom = v3d_dot(pl->normalized_vector, r.dir);
	if (fabs(denom) > 1e-6)
	{
		t = v3d_dot(v3d_opr_minus(pl->coordinates_point, r.orig), \
			pl->normalized_vector) / denom;
		if (t > MIN && t < t_max)
			return (set_rec(rec, t, pl->color));
	}
	return (F);
}
