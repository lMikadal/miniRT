#include "minirt.h"

t_ray get_ray(double u, double v, t_ca camera)
{
	t_v3d group_d_1;
	t_v3d group_d_2;
	t_v3d direct;

	group_d_1 = v3d_opr_plus(camera.l_l_c, v3d_mult_double(camera.horizontal, u));
	group_d_2 = v3d_opr_minus(v3d_mult_double(camera.vertical, v), camera.origin);
	direct = v3d_opr_plus(group_d_1, group_d_2);
	return (ray_create(camera.origin, direct));
}

t_ca create_camera(t_v3d lookfrom, t_v3d lookat, t_v3d vup, double fov, double aspect_ratio)
{
	t_ca camera;
	double view[2];
	t_v3d w;
	t_v3d u;
	t_v3d v;

	view[0] = 2.0 * tan((fov * PI / 180.0) / 2);
	view[1] = view[0] / aspect_ratio;
	w = v3d_unit_vec(v3d_opr_minus(lookfrom, lookat));
	u = v3d_unit_vec(v3d_cross(vup, w));
	v = v3d_cross(w, u);
	camera.origin = v3d_create(lookfrom.x, lookfrom.y, lookfrom.z);
	camera.horizontal = v3d_mult_double(u, view[0]);
	camera.vertical = v3d_mult_double(v, view[1]);
	camera.l_l_c = v3d_opr_minus(v3d_opr_minus(v3d_opr_minus(camera.origin, v3d_div_double(camera.horizontal, 2)), v3d_div_double(camera.vertical, 2)), w);
	return (camera);
}
