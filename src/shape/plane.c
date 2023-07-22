#include "minirt.h"

int plane(t_ray r)
{
    t_v3d point = v3d_create(0, 0, -10.0);
    t_v3d normal = v3d_create(0, -1, 0);

    double denom = v3d_dot(normal, r.dir);
    if (fabs(denom) > 1e-6)
    {
        double t = v3d_dot(v3d_opr_minus(point, r.orig), normal) / denom;
        if (t >= 0)
            return (1);
    }
    return (0);
}