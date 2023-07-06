#include "miniRT.h"

// int = bool
double	hit_sphere(t_v3d center, double rad, t_ray r)
{
	t_v3d	oc = v3d_opr_minus(r.orig, center);
	double	a = v3d_dot(r.dir, r.dir);
	double	b = 2.0 * v3d_dot(oc, r.dir);
	double	c = v3d_dot(oc, oc) - (rad * rad);
	double	discrim = (b * b) - (4 * a * c);
	if (discrim < 0.0)
		return -99999.0;
	else {
		// printf("discrim = %lf\n", discrim);
		double t = ((-b - sqrt(discrim)) / (2.0 * a));
		printf("tttt: %lf\n", t);
		return t;
	}
}

t_v3d	ray_color(t_ray r)
{
	double t = hit_sphere(v3d_create(0, 0, -1), 0.5, r);
	// printf("t: %lf\n", t);
	if (t != -99999.0)
	{
		t *= -1;
		t_v3d	N = v3d_unit_vec(v3d_opr_minus(ray_at(r, t), v3d_create(0, 0, -1)));
		return v3d_mult_double(v3d_create(N.x + 1.0, N.y + 1.0, N.z + 1.0), 0.5);
	}
	t_v3d	unit_dir = v3d_unit_vec(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return (v3d_opr_plus(v3d_mult_double(v3d_create(1.0, 1.0, 1.0), 1.0-t), v3d_mult_double(v3d_create(0.5, 0.7, 1.0), t)));
}

void	render(t_mlx *mlx, t_info *info)
{
	t_v3d	pix_color;
	t_rgb	rgb;
	double	ratio = 16.0 / 9.0;
	int		height = (int)(HORIZON/ratio);
	double	v_h = 2.0;
	double	v_w = ratio * v_h;
	double	f_len = 1.0;
	t_v3d	ori = v3d_create(0, 0, 0);
	t_v3d	hori = v3d_create(v_w, 0, 0);
	t_v3d	verti = v3d_create(0, v_h, 0);
	t_v3d	horiz2 = v3d_create(hori.x / 2.0, hori.y / 2.0,hori.z / 2.0);
	t_v3d	vert2 = v3d_create(verti.x / 2.0, verti.y / 2.0,verti.z / 2.0);
	t_v3d	lower_left = v3d_opr_minus(v3d_opr_minus(ori, horiz2), v3d_opr_minus(vert2, v3d_create(0, 0, f_len)));

	for (int j = VERTICAL - 1; j >= 0; --j)
	{
		for (int i = 0; i < HORIZON; ++i)
		{
			double	u = (double)i / (HORIZON - 1);
			double	v = (double)j / (height - 1);
			t_v3d	uhori = v3d_mult_double(hori, u);
			t_v3d	vverti = v3d_mult_double(verti, v);
			t_ray	r = ray_create(ori, v3d_opr_plus(v3d_opr_plus(lower_left, uhori), v3d_opr_minus(vverti, ori)));
			// printf("r: x = %lf  y = %lf  z = %lf\n", r.dir.x, r.dir.y, r.dir.z);
			
			pix_color = ray_color(r);
			rgb.r = 255.99 * pix_color.x;
			rgb.g = 255.99 * pix_color.y;
			rgb.b = 255.99 * pix_color.z;
			// printf("rgb: r = %d  g = %d  b = %d\n", rgb.r, rgb.g, rgb.b);
			// printf("pix_color: r = %lf  g = %lf  b = %lf\n", pix_color.x, pix_color.y, pix_color.z);
			ft_mlx_pixel_put(mlx, i, VERTICAL-j, ft_color(rgb));
		}
	}
}
