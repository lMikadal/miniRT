#include "miniRT.h"

// int = bool
// double	hit_sphere(t_v3d center, double rad, t_ray r)
// {
// 	t_v3d	oc = v3d_opr_minus(r.orig, center);
// 	double	a = v3d_dot(r.dir, r.dir);
// 	double	b = 2.0 * v3d_dot(oc, r.dir);
// 	double	c = v3d_dot(oc, oc) - (rad * rad);
// 	double	discrim = (b * b) - (4 * a * c);

// 	if (discrim < 0.0)
// 		return -99999.0;
// 	else {
// 		double t = ((-b - sqrt(discrim)) / (2.0 * a));
// 		return t;
// 	}
// }

// t_v3d	ray_color(t_ray r)
// {
// 	double t = hit_sphere(v3d_create(0, 0, -1), 0.5, r);
// 	if (t != -99999.0)
// 	{
// 		t *= -1;
// 		t_v3d	N = v3d_unit_vec(v3d_opr_minus(ray_at(r, t), v3d_create(0, 0, -1)));
// 		return v3d_mult_double(v3d_create(N.x + 1.0, N.y + 1.0, N.z + 1.0), 0.5);
// 	}
// 	t_v3d	unit_dir = v3d_unit_vec(r.dir);
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	return (v3d_opr_plus(v3d_mult_double(v3d_create(1.0, 1.0, 1.0), 1.0-t), v3d_mult_double(v3d_create(0.5, 0.7, 1.0), t)));
// }

// void	render(t_mlx *mlx, t_info *info)
// {
// 	t_v3d	pix_color;
// 	t_rgb	rgb;
// 	double	ratio = 16.0 / 9.0;
// 	int		height = (int)(HORIZON/ratio);
// 	double	v_h = 2.0;
// 	double	v_w = ratio * v_h;
// 	double	f_len = 1.0;
// 	t_v3d	ori = v3d_create(0, 0, 0);
// 	t_v3d	hori = v3d_create(v_w, 0, 0);
// 	t_v3d	verti = v3d_create(0, v_h, 0);
// 	t_v3d	horiz2 = v3d_create(hori.x / 2.0, hori.y / 2.0,hori.z / 2.0);
// 	t_v3d	vert2 = v3d_create(verti.x / 2.0, verti.y / 2.0,verti.z / 2.0);
// 	t_v3d	lower_left = v3d_opr_minus(v3d_opr_minus(ori, horiz2), v3d_opr_minus(vert2, v3d_create(0, 0, f_len)));

// 	for (int j = VERTICAL - 1; j >= 0; --j)
// 	{
// 		for (int i = 0; i < HORIZON; ++i)
// 		{
// 			double	u = (double)i / (HORIZON - 1);
// 			double	v = (double)j / (height - 1);
// 			t_v3d	uhori = v3d_mult_double(hori, u);
// 			t_v3d	vverti = v3d_mult_double(verti, v);
// 			t_ray	r = ray_create(ori, v3d_opr_plus(v3d_opr_plus(lower_left, uhori), v3d_opr_minus(vverti, ori)));
			
// 			pix_color = ray_color(r);
// 			rgb.r = 255.99 * pix_color.x;
// 			rgb.g = 255.99 * pix_color.y;
// 			rgb.b = 255.99 * pix_color.z;
// 			ft_mlx_pixel_put(mlx, i, VERTICAL-j, ft_color(rgb));
// 		}
// 	}
// }

double	hit_sphere(t_v3d center, double rad, t_ray r)
{
	t_v3d	oc = v3d_opr_minus(r.orig, center);
	double	a = v3d_length(r.dir);
	double	half_b = v3d_dot(oc, r.dir);
	double	c =  v3d_length(oc) - (rad * rad);
	double	discrim = (half_b * half_b) - (a * c);

	if (discrim < 0.0)
		return -99999.0;
	else {
		return ((-half_b - sqrt(discrim)) / a);
	}
}

t_v3d	ray_color(t_ray r)
{
	t_v3d	unit_dir;
	double	t;

	t = hit_sphere(v3d_create(0, 0, -1), 0.5, r);
	if (t != -99999.0) {
		t *= -1;
		t_v3d	N = v3d_unit_vec(v3d_opr_minus(ray_at(r, t), v3d_create(0, 0, -1)));
		return v3d_mult_double(v3d_create(N.x + 1.0, N.y + 1.0, N.z + 1.0), 0.5);
	}
	unit_dir = v3d_unit_vec(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return (v3d_opr_plus(v3d_mult_double(v3d_create(1.0, 1.0, 1.0), 1.0-t), v3d_mult_double(v3d_create(0.5, 0.7, 1.0), t)));
}

void	render(t_mlx *mlx, t_info *info)
{
	(void)info;
	t_rgb	rgb;
	double	u;
	double	v;
	t_v3d	pix_color;
	double	ratio;
	int		height;
	int		width;
	double	v_h;
	double	v_w;
	double	f_len;
	t_v3d	ori;
	t_v3d	hori;
	t_v3d	verti;
	t_v3d	lower_left;
	t_v3d	horiz2;
	t_v3d	vert2;
	t_ray	r;
	t_v3d	uhori;
	t_v3d	vverti;

	ratio = 16.0 / 9.0;
	width = 400;
	height = (int)(width/ratio);
	v_h = 2.0;
	v_w = ratio * v_h;
	f_len = 1.0;
	ori = v3d_create(0, 0, 0);
	hori = v3d_create(v_w, 0, 0);
	verti = v3d_create(0, v_h, 0);
	horiz2 = v3d_create(hori.x / 2.0, hori.y / 2.0,hori.z / 2.0);
	vert2 = v3d_create(verti.x / 2.0, verti.y / 2.0,verti.z / 2.0);
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