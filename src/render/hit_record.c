#include "minirt.h"

static void set_hit(int *hit, double *c_so_far, t_hit_record *rec, t_hit_record *tmp)
{
	*hit = T;
	*c_so_far = tmp->t;
	*rec = *tmp;
}

int hittable_list(t_ray r, double t_min, double t_max, t_hit_record *rec, t_info *info)
{
	t_hit_record tmp;
	int hit;
	double c_so_far;
	t_hittable_list *hittable;

	hit = F;
	c_so_far = t_max;
	hittable = info->hittable_list;
	while (hittable != NULL)
	{
		if (hittable->type == SP && sphere(r, t_min, c_so_far, &tmp, hittable->sphere))
			set_hit(&hit, &c_so_far, rec, &tmp);
		else if (hittable->type == PL && plane(r, t_min, c_so_far, &tmp, hittable->plane))
			set_hit(&hit, &c_so_far, rec, &tmp);
		else if (hittable->type == CY && cylinder(r, t_min, c_so_far, &tmp, hittable->cylinder))
			set_hit(&hit, &c_so_far, rec, &tmp);
		hittable = hittable->next;
	}
	return (hit);
}