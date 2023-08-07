#include "minirt.h"

void set_facae_normal(t_ray r, t_v3d outward_normal, t_hit_record *rec)
{
	if (v3d_dot(r.dir, outward_normal) > 0.0)
	{
		rec->normal = v3d_mult_minus(outward_normal);
		rec->front_face = F;
	}
	else
	{
		rec->normal = outward_normal;
		rec->front_face = T;
	}
}

int hittable_list(t_ray r, double t_min, double t_max, t_hit_record *rec, t_info *info)
{
	t_hit_record temp_rec;
	int hit_anything = F;
	double closest_so_far = t_max;
	t_hittable_list *hittable = info->hittable_list;

	while (hittable != NULL)
	{
		if (hittable->type == SP)
		{
			if (sphere(r, t_min, closest_so_far, &temp_rec, hittable->sphere))
			{
				hit_anything = T;
				closest_so_far = temp_rec.t;
				temp_rec.type = SP;
				*rec = temp_rec;
			}
		}
		else if (hittable->type == PL)
		{
			if (plane(r, t_min, closest_so_far, &temp_rec, hittable->plane))
			{
				hit_anything = T;
				closest_so_far = temp_rec.t;
				temp_rec.type = PL;
				*rec = temp_rec;
			}
		}
		else if (hittable->type == CY)
		{
			if (cylinder(r, t_min, closest_so_far, &temp_rec, hittable->cylinder))
			{
				hit_anything = T;
				closest_so_far = temp_rec.t;
				temp_rec.type = CY;
				*rec = temp_rec;
			}
		}
		hittable = hittable->next;
	}
	// printf("type: %d, t_max: %lf\n", rec->type, closest_so_far);

	return (hit_anything);
}