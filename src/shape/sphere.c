#include "minirt.h"

int sphere(t_ray r)
{
	t_v3d center = v3d_create(0, 0, 20.6);
	double radius = 12.6;

	t_v3d oc = v3d_opr_minus(r.orig, center);
	double a = v3d_length_squared(r.dir);
	double half_b = v3d_dot(oc, r.dir);
	double c = v3d_length_squared(oc) - (radius * radius);

	double discrim = (half_b * half_b) - (a * c);

	if (discrim < 0)
		return (0);
	return (1);
}