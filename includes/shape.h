/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:28:45 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:28:48 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

int		sphere(t_ray r, double t_max, t_hit_record *rec, t_sphere *sp);
int		plane(t_ray r, double t_max, t_hit_record *rec, t_plane *pl);
int		h_c(double t, t_cylinder *cy, \
			t_hit_record *rec, double denom);
t_v3d	find_t_dot(double dot, t_cylinder *cy, t_v3d tb[]);
int		cylinder(t_ray r, double t_max, t_hit_record *rec, t_cylinder *cy);
int		set_rec(t_hit_record *rec, double t, t_rgb color);

#endif
