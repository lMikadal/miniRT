/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:39:08 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/13 09:35:43 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cx_rgb_limit(t_rgb *a)
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

t_rgb	rgb_plus(t_rgb a, t_rgb b)
{
	t_rgb	rgb;

	rgb.r = a.r + b.r;
	rgb.g = a.g + b.g;
	rgb.b = a.b + b.b;
	cx_rgb_limit(&rgb);
	return (rgb);
}

t_rgb	rgb_create(double r, double g, double b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	rgb_ratio(t_rgb a, double ratio)
{
	t_rgb	rgb;

	rgb.r = a.r * ratio;
	rgb.g = a.g * ratio;
	rgb.b = a.b * ratio;
	return (rgb);
}

int	hitrec_cmp(t_hit_record a, t_hit_record b)
{
	if (a.type != b.type)
		return (0);
	if (a.p.x != b.p.x || a.p.y != b.p.y || a.p.z != b.p.z)
		return (0);
	
	return (1);
}

static t_rgb	ray_color(t_ray r, t_info *world)
{
	t_hit_record	rec;

	t_hit_record	tmp;
	t_ray			lightray;

	t_rgb	color = rgb_create(0, 0, 0);
	
	// camera hit object
	// if (hittable_list(r, INFINITY, &rec, world))
	// 	return (rec.color);
	

	// new code
	if (hittable_list(r, INFINITY, &rec, world))
	{
		lightray = ray_create(world->camera->coordinates_point, rec.p);
		if (hittable_list(lightray, INFINITY, &tmp, world))
		{
			if(hitrec_cmp(rec, tmp))
			{
				//to color;
				// position camera hit object
				// line from cam to pos hit obj
				// line that light will reflect from pos hit obj
				// find angle of light and reflect
				// find ratio of light

				// for test
				return (rgb_plus(world->product_amb, rec.color));
				// this will return color of object plus ambient plus light ratio

			}
			// this is shadow
			return (world->product_amb);
		}
		// find shadow and light
		// if from obj point hit other obj before reach light source
		//	return (world->product_amb);
		// else
		// find degree of light and reflect angle to find ratio of light


		// final product
		color = rgb_plus(world->product_amb, rec.color);
		return (color);
	}
	return (color);
}

void	init_more_info(t_info *info)
{
	info->product_amb = rgb_ratio(info->ambient->color, info->ambient->ratio);
}

void render(t_mlx *mlx)
{
	double ratio;
	int width;
	int height;
	t_ca camera;
	int loop[2];
	double view[2];
	t_camera	*cam;

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
