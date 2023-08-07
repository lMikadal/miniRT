#include "minirt.h"

t_rgb rgb_create(double r, double g, double b)
{
	t_rgb rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;

	return (rgb);
}

t_rgb ray_color(t_ray r, t_info *world)
{
	t_hit_record rec;

	if (hittable_list(r, 0.000, INFINITY, &rec, world))
		return (rec.color);
	return (rgb_create(0, 0, 0));
}

void render(t_mlx *mlx, t_info *info)
{

	// Image size
	double ratio = 16.0 / 9.0;
	int width = HORIZON;
	int height = width / ratio;

	// Camera
	t_ca camera = create_camera(v3d_create(info->camera->coordinates_point.x, info->camera->coordinates_point.y, info->camera->coordinates_point.z), v3d_create(0.0, 0, -1.0), v3d_create(info->camera->normalized_vector.x, info->camera->normalized_vector.y, info->camera->normalized_vector.z), info->camera->fov, ratio);

	for (int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			double u = (double)i / (width - 1);
			double v = (double)j / (height - 1);

			t_ray r = get_ray(u, v, camera);
			t_rgb rgb = ray_color(r, info);

			// if (height - j != height)
			ft_mlx_pixel_put(mlx, i, height - j, ft_color(rgb));
			// else
			// 	ft_mlx_pixel_put(mlx, i, 0, ft_color(rgb));
		}
	}
}