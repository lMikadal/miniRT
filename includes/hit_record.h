#ifndef HIT_RECORD_H
#define HIT_RECORD_H

typedef struct s_hit_record
{
	t_v3d p;
	t_v3d normal;
	double t;
	int front_face;
	int type;
	t_rgb color;
} t_hit_record;

void set_facae_normal(t_ray r, t_v3d outward_normal, t_hit_record *rec);
int hittable_list(t_ray r, double t_min, double t_max, t_hit_record *rec, t_info *info);

#endif