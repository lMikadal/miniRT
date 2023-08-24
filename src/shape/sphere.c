#include "minirt.h"

int sphere(t_ray r, double t_min, double t_max, t_hit_record *rec, t_sphere *sp)
{
	t_v3d center = sp->coordinates_center;
	double radius = sp->diameter / 2;

	t_v3d oc = v3d_opr_minus(r.orig, center);
	double a = v3d_dot(r.dir, r.dir);
	double b = 2.0 * v3d_dot(oc, r.dir);
	double c = v3d_dot(oc, oc) - (radius * radius);

	double discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (F);

	double sqrtd = sqrt(discriminant);
	double root = ((b * -1) - sqrtd) / (2.0 * a);
	if (root < t_min || t_max <= root)
	{
		root = ((b * -1) + sqrtd) / (2.0 * a);
		if (root < t_min || t_max <= root)
			return (F);
	}
	rec->t = root;
	rec->color = rgb_create(sp->color.r, sp->color.g, sp->color.b);

	return (T);
}