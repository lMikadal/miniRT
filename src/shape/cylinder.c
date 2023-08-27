#include "minirt.h"

int hit_cap(t_cylinder *cy, t_ray r, double t_min, double dot, t_hit_record *rec)
{
	double denom = v3d_dot(cy->normalized_vector, r.dir);
	double t;
	t_v3d half_h = v3d_mult_double(cy->normalized_vector, cy->height / 2);
	t_v3d top = v3d_opr_plus(cy->coordinates_center, half_h);
	t_v3d bottom = v3d_opr_minus(cy->coordinates_center, half_h);
	if (fabs(denom) >= t_min)
	{
		if (dot >= cy->height / 2)
			t = v3d_dot(v3d_opr_minus(top, r.orig), cy->normalized_vector) / denom;
		else if (dot <= (cy->height * -1) / 2)
			t = v3d_dot(v3d_opr_minus(bottom, r.orig), cy->normalized_vector) / denom;
		if (t >= t_min)
		{
			t_v3d p = ray_at(r, t);
			t_v3d v;
			if (dot >= cy->height / 2)
				v = v3d_opr_minus(p, top);
			else
				v = v3d_opr_minus(p, bottom);
			double v_dot = v3d_dot(v, v);
			if (sqrtf(v_dot) <= cy->radius)
				return (set_rec(rec, t, cy->color));
		}
	}
	return (F);
}

int hit_body(t_ray r, double t, t_cylinder *cy, double *dot)
{
	t_v3d point = ray_at(r, t);
	t_v3d ori_diff = v3d_opr_minus(point, cy->coordinates_center);
	*dot = v3d_dot(ori_diff, cy->normalized_vector);

	if (fabs(*dot) >= cy->height / 2)
		return (F);
	return (T);
}

int cylinder(t_ray r, double t_max, t_hit_record *rec, t_cylinder *cy)
{
	t_v3d oc = v3d_opr_minus(r.orig, cy->coordinates_center);

	double sub_a = pow(v3d_dot(r.dir, cy->normalized_vector), 2);
	double a = v3d_dot(r.dir, r.dir) - sub_a;

	double sub_b = v3d_dot(r.dir, cy->normalized_vector) * v3d_dot(oc, cy->normalized_vector);
	double b = (v3d_dot(r.dir, oc) - sub_b);

	double sub_c = pow(v3d_dot(oc, cy->normalized_vector), 2);
	double c = v3d_dot(oc, oc) - sub_c - (cy->radius * cy->radius);

	double discrim = (b * b) - (a * c);
	if (discrim < 0)
		return (F);

	double sqrtd = sqrt(discrim);
	double t1 = ((b * -1) - sqrtd) / a;
	double t2 = ((b * -1) + sqrtd) / a;
	double t = t1;

	if (t1 > t2)
		t = t2;
	// double dot;
	if (t > MIN && t <= t_max)// && hit_body(r, t, cy, &dot) != F)
		return (set_rec(rec, t, cy->color));
	return (F);
	// return (hit_cap(cy, r, t_min, dot, rec));
}