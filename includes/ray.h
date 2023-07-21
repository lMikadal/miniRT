/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:57:17 by pruangde          #+#    #+#             */
/*   Updated: 2023/07/02 13:33:06 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

typedef struct s_ray
{
	t_v3d orig;
	t_v3d dir;
} t_ray;

t_ray ray_create(t_v3d o, t_v3d d);
t_v3d ray_at(t_ray r, double t);

#endif
