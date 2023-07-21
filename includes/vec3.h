/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:28:59 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/02 13:40:29 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
#define VEC3_H

typedef struct s_vec3d
{
	double x;
	double y;
	double z;
} t_v3d;

t_v3d v3d_create(double x, double y, double z);
double v3d_length_squared(t_v3d v);
double v3d_length(t_v3d v);
t_v3d v3d_normalize(t_v3d v);
double v3d_dot(t_v3d a, t_v3d b);
t_v3d v3d_cross(t_v3d a, t_v3d b);
t_v3d v3d_opr_plus(t_v3d a, t_v3d b);
t_v3d v3d_opr_minus(t_v3d a, t_v3d b);
t_v3d v3d_opr_mult(t_v3d a, t_v3d b);
t_v3d v3d_opr_div(t_v3d a, t_v3d b);
void v3d_add2(t_v3d *a, t_v3d b);
void v3d_mult2(t_v3d *a, t_v3d b);
void v3d_div2(t_v3d *a, double b);
t_v3d v3d_mult_double(t_v3d a, double b);
t_v3d v3d_unit_vec(t_v3d a);

#endif
