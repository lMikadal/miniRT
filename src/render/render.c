/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:39:08 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:39:10 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	rgb_create(double r, double g, double b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

static t_rgb	ray_color(t_ray r, t_info *world)
{
	t_hit_record	rec;

	if (hittable_list(r, INFINITY, &rec, world))
		return (rec.color);
	return (rgb_create(0, 0, 0));
}

void render(t_mlx *mlx)
{
	double ratio;
	int width;
	int height;
	t_ca camera;
	int loop[2];
	double view[2];

	// Image size
	double ratio = 16.0 / 9.0;
	int width = HORIZON;
	int height = width / ratio;

	t_camera	*cam = mlx->info->camera;
	// Camera
	t_ca camera = create_camera(cam->coordinates_point, cam->normalized_vector, v3d_create(0, 1, 0), cam->fov, ratio);

	for (int j = height - 1; j >= 0; --j)
	{
		loop[1] = 0;
		while (loop[1]++ < width)
		{
			double u = (double)i / (width - 1);
			double v = (double)j / (height - 1);

			t_ray r = get_ray(u, v, camera);
			t_rgb rgb = ray_color(r, mlx->info);

			// if (height - j != height)
			ft_mlx_pixel_put(mlx, i, height - j, ft_color(rgb));
			// else
			// 	ft_mlx_pixel_put(mlx, i, 0, ft_color(rgb));
		}
	}
}
