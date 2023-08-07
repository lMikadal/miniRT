#include "minirt.h"

int plane(t_ray r, double t_min, double t_max, t_hit_record *rec, t_plane *pl)
{
	double t;
	double denom = v3d_dot(pl->normalized_vector, r.dir);

	if (fabs(denom) > 1e-6)
	{
		t = v3d_dot(v3d_opr_minus(pl->coordinates_point, r.orig), pl->normalized_vector) / denom;
		if (t < 0.0)
			return (F);
	}
	// printf("t: %lf, t_max: %lf\n", t, t_max);
	if (t < t_min || t > t_max)
		return (F);

	rec->t = t;
	rec->p = ray_at(r, rec->t);
	rec->color = rgb_create(pl->color.r, pl->color.g, pl->color.b);

	return (T);
}