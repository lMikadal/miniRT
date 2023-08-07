#include "minirt.h"

int cylinder(t_ray r)
{
    t_v3d center = v3d_create(50, 0, 20.6);
    double radius = 14.2 / 2;
    double height = 21.42;
    t_v3d oc = v3d_opr_minus(r.orig, center);

    double sub_a = pow(v3d_dot(r.dir, v3d_create(height, height, height)), 2);
    double a = v3d_dot(r.dir, r.dir) - sub_a;

    double sub_b = v3d_dot(r.dir, v3d_create(height, height, height)) * v3d_dot(oc, v3d_create(height, height, height));
    double b = (v3d_dot(r.dir, oc) - sub_b) * 2.0;

    double sub_c = pow(v3d_dot(oc, v3d_create(height, height, height)), 2);
    double c = v3d_dot(oc, oc) - sub_c - (radius * radius);

    double discrim = (b * b) - (4 * a * c);

    double t = ((b * -1) - sqrt(discrim)) / (2.0 * a);

    double check = (v3d_dot(r.dir, v3d_create(height, height, height)) * t) + v3d_dot(oc, v3d_create(height, height, height));

    if (check < 0)
        return (0);
    return (1);
}