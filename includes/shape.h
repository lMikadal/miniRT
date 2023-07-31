#ifndef SHAPE_H
#define SHAPE_H

int sphere(t_ray r, double t_min, double t_max, t_hit_record *rec, t_sphere *sp);
int plane(t_ray r);
int cylinder(t_ray r);

#endif