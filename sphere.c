#include "miniRT.h"

int	ft_sphere(t_ray r, double t_min, double t_max, t_hit_record *rec, t_sphere *sphere)
{
	t_v3d	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_v3d	center;
	t_v3d	outward_normal;
	double	rad;

	rad = sphere->diameter / 2;
	center = v3d_create(sphere->center[0], sphere->center[1], sphere->center[2]);
	oc = v3d_opr_minus(r.orig, center);
	a = v3d_length(r.dir); 
	half_b = v3d_dot(oc, r.dir);
	c =  v3d_length(oc) - (rad * rad);
	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0)
		return (F);
	sqrtd = (double)sqrt(discriminant);
	root = ((half_b * -1) - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = ((half_b * -1) + sqrtd) / a;
		if (root < t_min || t_max < root)
			return (F);
	}
	rec->t = root;
	rec->p = ray_at(r, rec->t);
	outward_normal = v3d_mult_double(v3d_opr_minus(rec->p, center), rad);
	set_face_normal(r, outward_normal, rec);
	return (T);
}