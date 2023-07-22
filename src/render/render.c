#include "minirt.h"

t_v3d ray_color(t_ray r)
{
	t_v3d unit_dir;
	double t;

	t = plane(r);
	if (t == 1)
	{
		return v3d_create(0, 255, 0);
	}
	unit_dir = v3d_unit_vec(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return (v3d_opr_plus(v3d_mult_double(v3d_create(1.0, 1.0, 1.0), 1.0 - t), v3d_mult_double(v3d_create(0.5, 0.7, 1.0), t)));
}

void render(t_mlx *mlx, t_info *info)
{

	(void)info;
	t_rgb rgb;
	double u;
	double v;
	t_v3d pix_color;
	double ratio;
	int height;
	int width;
	double v_h;
	double v_w;
	double f_len;
	t_v3d ori;
	t_v3d hori;
	t_v3d verti;
	t_v3d lower_left;
	t_v3d horiz2;
	t_v3d vert2;
	t_ray r;
	t_v3d uhori;
	t_v3d vverti;

	ratio = 16.0 / 9.0;
	width = HORIZON;
	height = (int)(width / ratio);
	v_h = 2.0;
	v_w = ratio * v_h;
	f_len = 1.0;
	ori = v3d_create(0, 0, 0);
	hori = v3d_create(v_w, 0, 0);
	verti = v3d_create(0, v_h, 0);
	horiz2 = v3d_create(hori.x / 2.0, hori.y / 2.0, hori.z / 2.0);
	vert2 = v3d_create(verti.x / 2.0, verti.y / 2.0, verti.z / 2.0);
	lower_left = v3d_opr_minus(v3d_opr_minus(ori, horiz2), v3d_opr_minus(vert2, v3d_create(0, 0, f_len)));

	for (int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			u = (double)i / (width - 1);
			v = (double)j / (height - 1);
			uhori = v3d_mult_double(hori, u);
			vverti = v3d_mult_double(verti, v);
			r = ray_create(ori, v3d_opr_plus(v3d_opr_plus(lower_left, uhori), v3d_opr_minus(vverti, ori)));

			pix_color = ray_color(r);
			rgb.r = 255.99 * pix_color.x;
			rgb.g = 255.99 * pix_color.y;
			rgb.b = 255.99 * pix_color.z;

			if (height - j != height)
				ft_mlx_pixel_put(mlx, i, height - j, ft_color(rgb));
			else
				ft_mlx_pixel_put(mlx, i, 0, ft_color(rgb));
		}
	}
}