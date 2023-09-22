/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:36:53 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 08:01:24 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v2d_dot(t_v2d a, t_v2d b)
{
	return (a.x * b.x + a.y * b.y);
}

double	v2d_length(t_v2d v)
{
	return (sqrt(v2d_dot(v, v)));
}

t_v2d	v2d_create(double x, double y)
{
	t_v2d	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_v2d	v2d_rotate(t_v2d v, double degree)
{
	t_v2d	rot;
	double	rad;
	double	sine;
	double	cosine;

	rad = degree * (PI / 180);
	sine = sin(rad);
	cosine = cos(rad);
	rot.x = v.x * cosine - v.y * sine;
	rot.y = v.x * sine + v.y * cosine;
	return (rot);
}

void	err_key(int mode)
{
	if (mode == 1)
		printf("Invalid key\n");
	else if (mode == 2)
		printf("Invalid key for selected object\n");
}
