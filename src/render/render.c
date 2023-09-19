/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:39:08 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/18 13:31:49 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	shading(t_rgb color, t_hit_record rec, t_info *world)
{
	t_shading	shading;

	shading.lgtdir = v3d_opr_minus(world->light->coordinates_point, rec.p);
	shading.two_dot = v3d_dot(rec.normal, shading.lgtdir);
	shading.cam_len = v3d_length(rec.normal);
	shading.lgt_len = v3d_length(shading.lgtdir);
	shading.angle = acos(shading.two_dot / (shading.cam_len * shading.lgt_len));
	shading.angle = 1 - (shading.angle * 2.0 / PI);
	color = rgb_plus(rgb_ratio(color, shading.angle), \
		rgb_ratio(world->product_light, shading.angle * 0.2));
	return (rgb_plus(color, world->product_amb));
}

static t_rgb	ray_color(t_ray r, t_info *world)
{
	t_hit_record	rec;
	t_hit_record	tmp;
	t_ray			lightray;
	t_rgb			color;

	color = rgb_create(0, 0, 0);
	if (hittable_list(r, INFINITY, &rec, world))
	{
		color = rgb_plus(world->product_amb, rec.color);
		lightray.orig = rec.p;
		lightray.dir = world->light->coordinates_point;
		if (!hittable_list(lightray, INFINITY, &tmp, world))
			return (shading(color, rec, world));
		return (world->product_amb);
	}
	return (color);
}

void	init_more_info(t_info *info)
{
	info->product_amb = rgb_ratio(info->ambient->color, info->ambient->ratio);
	info->product_light = rgb_ratio(info->light->color, info->light->ratio);
}

void	render(t_mlx *mlx)
{
	t_ca		camera;
	int			loop[3];
	double		view[3];
	t_camera	*cam;

	camera.unit.ratio = 16.0 / 9.0;
	loop[2] = HORIZON / camera.unit.ratio;
	init_more_info(mlx->info);
	cam = mlx->info->camera;
	camera.unit.fov = cam->fov;
	camera = create_camera(cam->coordinates_point, \
				cam->normalized_vector, v3d_create(0, 1, 0), camera.unit);
	loop[0] = loop[2] - 1;
	while (loop[0]-- >= 0)
	{
		loop[1] = 0;
		while (loop[1]++ < HORIZON)
		{
			view[0] = (double)loop[1] / (HORIZON - 1);
			view[1] = (double)loop[0] / (loop[2] - 1);
			ft_mlx_pixel_put(mlx, loop[1], loop[2] - loop[0], \
					ft_color(ray_color(get_ray(view[0], view[1], camera), \
						mlx->info)));
		}
	}
}
