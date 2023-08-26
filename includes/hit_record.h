#ifndef HIT_RECORD_H
# define HIT_RECORD_H

typedef struct s_hit_record
{
	t_v3d	p;
	t_v3d	normal;
	double	t;
	int		front_face;
	int		type;
	t_rgb	color;
}	t_hit_record;

int	hittable_list(t_ray r, double t_max, t_hit_record *rec, t_info *info);

#endif