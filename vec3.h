/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:28:59 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/01 14:39:49 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}		t_v3i;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}			t_v3d;

void	v3d_create(t_v3d *v, double x, double y, double z);
double	v3d_length(t_v3d v);
t_v3d	v3d_normalize(t_v3d v);
double	v3d_dot(t_v3d *a, t_v3d *b);
t_v3d	v3d_cross(t_v3d a, t_v3d b);
t_v3d	v3d_opr_plus(t_v3d a, t_v3d b);
t_v3d	v3d_opr_minus(t_v3d a, t_v3d b);
t_v3d	v3d_opr_mult(t_v3d a, t_v3d b);

#endif
