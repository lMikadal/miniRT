#ifndef HITTABLE_H
# define HITTABLE_H

# include "vec3.h"

typedef struct s_hit_record
{
	t_v3d	p;
	t_v3d	normal;
	double	t;
	int		bool_front_face;
}	t_hit_record;

#endif