#include "minirt.h"

int sphere(t_ray r)
{
	t_v3d center = v3d_create(0, 0, 20.6);
	double radius = 12.6 / 2;

	t_v3d oc = v3d_opr_minus(r.orig, center);
	double a = v3d_dot(r.dir, r.dir);
	double b = 2.0 * v3d_dot(oc, r.dir);
	double c = v3d_dot(oc, oc) - (radius * radius);

	double discrim = (b * b) - (4 * a * c);

	if (discrim < 0)
		return (0);
	return (1);
}