#include "minirt.h"

int cylinder(t_ray r, double t_min, double t_max, t_hit_record *rec, t_cylinder *cy)
{
	t_v3d center = v3d_create(cy->coordinates_center.x, cy->coordinates_center.y, cy->coordinates_center.z);
	double radius = cy->diameter / 2;
	// double height = cy->height;
	t_v3d normal = v3d_create(cy->normalized_vector.x, cy->normalized_vector.y, cy->normalized_vector.z);
	t_v3d oc = v3d_opr_minus(r.orig, center);

	double sub_a = pow(v3d_dot(r.dir, normal), 2);
	double a = v3d_dot(r.dir, r.dir) - sub_a;

	double sub_b = v3d_dot(r.dir, normal) * v3d_dot(oc, normal);
	double b = (v3d_dot(r.dir, oc) - sub_b);

	double sub_c = pow(v3d_dot(oc, normal), 2);
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

	if (t < t_min || t_max <= t)
		return (F);

	// double check = (v3d_dot(r.dir, v3d_create(height, height, height)) * t) + v3d_dot(oc, v3d_create(height, height, height));

	// double check = r.orig.y + (r.dir.y * t);
	// if (check < cy->coordinates_center.z || cy->coordinates_center.z + cy->height < check)
	// 	return (F);

	rec->t = t;
	// rec->p = ray_at(r, rec->t);
	rec->color = rgb_create(cy->color.r, cy->color.g, cy->color.b);

	return (T);

	// new check intersection
	// (void)t_min;
	// (void)t_max;

	// double a = pow(r.dir.x, 2) + pow(r.dir.z, 2);
	// double b = 2 * ((r.dir.x * (r.orig.x - cy->coordinates_center.x)) + (r.dir.z * (r.orig.z - cy->coordinates_center.z)));
	// double c = (r.orig.x - cy->coordinates_center.x) * (r.orig.x - cy->coordinates_center.x) + (r.orig.z - cy->coordinates_center.z) * (r.orig.z - cy->coordinates_center.z) - pow(radius, 2);

	// double discrim = (b * b) - (4 * a * c);
	// if (discrim < 0 || fabs(discrim) < 0)
	// 	return (F);

	// double sqrtd = sqrt(discrim);
	// double t1 = ((b * -1) - sqrtd) / (2.0 * a);
	// double t2 = ((b * -1) + sqrtd) / (2.0 * a);
	// double t = t1;

	// if (t1 > t2)
	// 	t = t2;

	// double check = r.orig.y + (r.dir.y * t);

	// if (check < cy->coordinates_center.y || cy->coordinates_center.y + cy->height < check)
	// 	return (F);

	// rec->color = rgb_create(cy->color.r, cy->color.g, cy->color.b);

	// return (T);
}
