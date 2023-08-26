/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:40:02 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/26 23:40:06 by pmikada          ###   ########.fr       */
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

	if (hittable_list(r, &rec, world))
		return (rec.color);
	return (rgb_create(0, 0, 0));
}

void	render(t_mlx *mlx, t_info *info)
{
	double	ratio;
	int		size;
	int		loop[2];
	double	view[2];
	double	data[2];

	ratio = 16.0 / 9.0;
	size = HORIZON / ratio;
	data[0] = ratio;
	data[1] = info->camera->fov;
	loop[0] = size - 1;
	while (loop[0]-- >= 0)
	{
		loop[1] = 0;
		while (loop[1]++ < HORIZON)
		{
			view[0] = (double)loop[1] / (HORIZON - 1);
			view[1] = (double)loop[0] / (size - 1);
			ft_mlx_pixel_put(mlx, loop[1], size - loop[0], \
				ft_color(ray_color(get_ray(view[0], view[1], \
					create_camera(info->camera->coordinates_point, \
						v3d_create(0.0, 0, -1.0), \
							info->camera->normalized_vector, data)), info)));
		}
	}
}
