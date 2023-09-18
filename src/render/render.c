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

static void cx_rgb_limit(t_rgb *a)
{
	if (a->r > 255)
		a->r = 255;
	else if (a->r < 0)
		a->r = 0;
	if (a->g > 255)
		a->g = 255;
	else if (a->g < 0)
		a->g = 0;
	if (a->b > 255)
		a->b = 255;
	else if (a->b < 0)
		a->b = 0;
}

t_rgb rgb_plus(t_rgb a, t_rgb b)
{
	t_rgb rgb;

	rgb.r = a.r + b.r;
	rgb.g = a.g + b.g;
	rgb.b = a.b + b.b;
	cx_rgb_limit(&rgb);
	return (rgb);
}

t_rgb	rgb_minus(t_rgb a, t_rgb b)
{
	t_rgb rgb;

	rgb.r = a.r - b.r;
	rgb.g = a.g - b.g;
	rgb.b = a.b - b.b;
	cx_rgb_limit(&rgb);
	return (rgb);
}

t_rgb rgb_create(double r, double g, double b)
{
	t_rgb rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb rgb_ratio(t_rgb a, double ratio)
{
	t_rgb rgb;

	rgb.r = a.r * ratio;
	rgb.g = a.g * ratio;
	rgb.b = a.b * ratio;
	return (rgb);
}








static t_rgb ray_color(t_ray r, t_info *world)
{
	t_hit_record rec;

	t_hit_record tmp;
	t_ray lightray;

	t_rgb color = rgb_create(0, 0, 0);

	// camera hit object old origin code
	// if (hittable_list(r, INFINITY, &rec, world))
	// 	return (rec.color);

	// new code
	if (hittable_list(r, INFINITY, &rec, world))
	{
		color = rgb_plus(world->product_amb, rec.color);
		// t_v3d dirtmp = v3d_opr_minus(rec.p, world->light->coordinates_point);
		lightray.orig = rec.p;
		lightray.dir = world->light->coordinates_point;
		if (!hittable_list(lightray, INFINITY, &tmp, world))
		{
			// t_v3d	camdir = v3d_opr_minus(world->camera->coordinates_point, rec.p);
			t_v3d	lgtdir = v3d_opr_minus(world->light->coordinates_point, rec.p);
			


			double	two_dot = v3d_dot(rec.normal, lgtdir);
			double	cam_len = v3d_length(rec.normal);
			double	lgt_len = v3d_length(lgtdir);
		
			double	angle = acos(two_dot / (cam_len * lgt_len));

			angle = 1 - (angle * 2.0 / PI);
			

			// color = amb + (product light + color) *
			color = rgb_ratio(color, angle);
			t_rgb rgb = rgb_ratio(world->product_light, angle * 0.2);
			color = rgb_plus(color, rgb);
			// if (rec.type == CY)
			// 	printf("normal = %f %f %f\n", rec.normal.x, rec.normal.y, rec.normal.z);

			// double	angle = v3d_dot(lightray.dir, r.dir);
			// angle /= (v3d_length(lightray.dir) * v3d_length(r.dir));
			// double	dot = v3d_dot(camdir, hitlgt);
			// double angle = acos(dot / (v3d_norm(camdir) * v3d_norm(hitlgt)));
			return (rgb_plus(color, world->product_amb));
		}
		// this is shadow
		// return (world->product_amb);
		// final product
		return (world->product_amb);
	}
	return (color);
}

void init_more_info(t_info *info)
{
	info->product_amb = rgb_ratio(info->ambient->color, info->ambient->ratio);
	info->product_light = rgb_ratio(info->light->color, info->light->ratio);
}

void render(t_mlx *mlx)
{
	double ratio;
	int width;
	int height;
	t_ca camera;
	int loop[2];
	double view[2];
	t_camera *cam;

	ratio = 16.0 / 9.0;
	width = HORIZON;
	height = width / ratio;

	// init ambient
	init_more_info(mlx->info);
	// Camera
	cam = mlx->info->camera;
	camera = create_camera(cam->coordinates_point, cam->normalized_vector, v3d_create(0, 1, 0), cam->fov, ratio);

	loop[0] = height - 1;
	while (loop[0]-- >= 0)
	{
		loop[1] = 0;
		while (loop[1]++ < width)
		{
			view[0] = (double)loop[1] / (width - 1);
			view[1] = (double)loop[0] / (height - 1);
			ft_mlx_pixel_put(mlx, loop[1], height - loop[0], ft_color(ray_color(get_ray(view[0], view[1], camera), mlx->info)));
		}
	}
}
