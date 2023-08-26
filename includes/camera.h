/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:31:33 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/26 23:31:35 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_ca
{
	t_v3d	origin;
	t_v3d	horizontal;
	t_v3d	vertical;
	t_v3d	l_l_c;
}	t_ca;

t_ray	get_ray(double u, double v, t_ca camera);
t_ca	create_camera(t_v3d lookfrom, t_v3d lookat, t_v3d vup, double data);

#endif
