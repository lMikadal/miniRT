#include "minirt.h"

int cylinder(t_ray r, double t_min, double t_max, t_hit_record *rec, t_cylinder *cy)
{
	t_v3d center = v3d_create(cy->coordinates_center.x, cy->coordinates_center.y, cy->coordinates_center.z);
	double radius = cy->diameter / 2;
	double height = cy->height;
	t_v3d oc = v3d_opr_minus(r.orig, center);

	double sub_a = pow(v3d_dot(r.dir, v3d_create(height, height, height)), 2);
	double a = v3d_dot(r.dir, r.dir) - sub_a;

	double sub_b = v3d_dot(r.dir, v3d_create(height, height, height)) * v3d_dot(oc, v3d_create(height, height, height));
	double b = (v3d_dot(r.dir, oc) - sub_b) * 2.0;

	double sub_c = pow(v3d_dot(oc, v3d_create(height, height, height)), 2);
	double c = v3d_dot(oc, oc) - sub_c - (radius * radius);

	double discrim = (b * b) - (4 * a * c);

	if (discrim < 0)
		return (F);

	double sqrtd = sqrt(discrim);
	double t = ((b * -1) - sqrtd) / (2.0 * a);

	if (t < t_min || t_max <= t)
	{
		t = ((b * -1) + sqrtd) / (2.0 * a);
		if (t < t_min || t_max <= t)
			return (F);
	}

	double check = (v3d_dot(r.dir, v3d_create(height, height, height)) * t) + v3d_dot(oc, v3d_create(height, height, height));

	rec->t = check;
	rec->p = ray_at(r, rec->t);
	rec->color = rgb_create(cy->color.r, cy->color.g, cy->color.b);

	return (T);
}