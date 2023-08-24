#include "minirt.h"

int hit_body(t_ray r, double t, t_cylinder *cy)
{
	t_v3d point = ray_at(r, t);
	t_v3d ori_diff = v3d_opr_minus(point, cy->coordinates_center);
	double dot = v3d_dot(ori_diff, cy->normalized_vector);

	if (fabs(dot) > cy->height / 2)
		return (-1);
	return (1);
}

int cylinder(t_ray r, double t_min, double t_max, t_hit_record *rec, t_cylinder *cy)
{
	double radius = cy->diameter / 2;
	t_v3d oc = v3d_opr_minus(r.orig, cy->coordinates_center);

	double sub_a = pow(v3d_dot(r.dir, cy->normalized_vector), 2);
	double a = v3d_dot(r.dir, r.dir) - sub_a;

	double sub_b = v3d_dot(r.dir, cy->normalized_vector) * v3d_dot(oc, cy->normalized_vector);
	double b = (v3d_dot(r.dir, oc) - sub_b);

	double sub_c = pow(v3d_dot(oc, cy->normalized_vector), 2);
	double c = v3d_dot(oc, oc) - sub_c - (radius * radius);

	double discrim = (b * b) - (a * c);
	if (discrim < 0)
		return (F);

	double sqrtd = sqrt(discrim);
	double t1 = ((b * -1) - sqrtd) / a;
	double t2 = ((b * -1) + sqrtd) / a;
	double t = t1;

	if (t1 > t2)
		t = t2;
	if (t > t_min && t < t_max && hit_body(r, t, cy) != -1)
	{
		rec->t = t;
		rec->color = rgb_create(cy->color.r, cy->color.g, cy->color.b);
		return (T);
	}
	return (F);
}