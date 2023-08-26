#ifndef SHAPE_H
# define SHAPE_H

int	sphere(t_ray r, double t_max, t_hit_record *rec, t_sphere *sp);
int	plane(t_ray r, double t_max, t_hit_record *rec, t_plane *pl);
int	cylinder(t_ray r, double t_max, t_hit_record *rec, t_cylinder *cy);
int	set_rec(t_hit_record *rec, double t, t_rgb color);

#endif