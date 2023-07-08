#include "miniRT.h"

void	set_face_normal(t_ray r, t_v3d outward_normal, t_hit_record *record)
{
	if (v3d_dot(r.dir, outward_normal) < 0.0)
	{
		record->bool_front_face = T;
		record->normal = outward_normal;
	}
	else
	{
		record->bool_front_face = F;
		record->normal = v3d_mult_double(outward_normal, -1.0);
	}
}

int	hittable_list(t_ray r, double t_min, double t_max, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	int				hit_anything;
	double			closest_so_far;
	int				i;

	hit_anything = F;
	closest_so_far = t_max;
	i = 0;
	while(rec[i])
	{
		if()
	}
}