#include "minirt.h"

int plane(t_ray r)
{
    t_v3d normal = v3d_create(20, 30, -10.0);
    t_v3d point = v3d_create(0, 1.0, 0);
    double denom = v3d_dot(r.dir, normal);
    if (fabs(denom) > 1e-6)
    {
        t_v3d p0l0 = v3d_opr_minus(point, r.orig);
        double t = v3d_dot(p0l0, normal) / denom;
        if (t >= 0)
            return (1);
    }
    return (0);
}