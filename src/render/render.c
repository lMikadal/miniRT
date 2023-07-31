#include "minirt.h"

t_v3d ray_color(t_ray r)
{
	double t = sphere(r);
	if (t > 0.0)
		return (v3d_create(1.0, 0.0, 0.0));
	t_v3d unit_dir = v3d_unit_vec(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return (v3d_opr_plus(v3d_mult_double(v3d_create(1.0, 1.0, 1.0), 1.0 - t), v3d_mult_double(v3d_create(0.5, 0.7, 1.0), t)));
}

void render(t_mlx *mlx, t_info *info)
{

	(void)info;

	// Image size
	double ratio = 16.0 / 9.0;
	int width = HORIZON;
	int height = width / ratio;

	// Camera
	t_ca camera = create_camera(v3d_create(0.0, 0.0, 0.0), v3d_create(0.0, 0, 100.0), v3d_create(0.0, 1.0, 0.0), 90, ratio);

	for (int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			double u = (double)i / (width - 1);
			double v = (double)j / (height - 1);

			t_ray r = get_ray(u, v, camera);
			t_v3d pix_color = ray_color(r);

			// wirte_color [pix_color];
			t_rgb rgb;
			rgb.r = 255.99 * pix_color.x;
			rgb.g = 255.99 * pix_color.y;
			rgb.b = 255.99 * pix_color.z;

			// if (height - j != height)
			ft_mlx_pixel_put(mlx, i, height - j, ft_color(rgb));
			// else
			// 	ft_mlx_pixel_put(mlx, i, 0, ft_color(rgb));
		}
	}
}