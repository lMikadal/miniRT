#include "minirt.h"

t_ray get_ray(double u, double v, t_ca camera)
{

    t_v3d group_d_1 = v3d_opr_plus(camera.l_l_c, v3d_mult_double(camera.horizontal, u));
    t_v3d group_d_2 = v3d_opr_minus(v3d_mult_double(camera.vertical, v), camera.origin);
    t_v3d direct = v3d_opr_plus(group_d_1, group_d_2);

    return (ray_create(camera.origin, direct));
}

t_ca create_camera(t_v3d lookfrom, t_v3d lookat, t_v3d vup, double fov, double aspect_ratio)
{
    t_ca camera;

    double theta = fov * PI / 180.0;
    double h = tan(theta / 2);
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    t_v3d w = v3d_unit_vec(v3d_opr_minus(lookfrom, lookat));
    t_v3d u = v3d_unit_vec(v3d_cross(vup, w));
    t_v3d v = v3d_cross(w, u);

    camera.origin = v3d_create(lookfrom.x, lookfrom.y, lookfrom.z);
    camera.horizontal = v3d_mult_double(u, viewport_width);
    camera.vertical = v3d_mult_double(v, viewport_height);
    camera.l_l_c = v3d_opr_minus(v3d_opr_minus(v3d_opr_minus(camera.origin, v3d_div_double(camera.horizontal, 2)), v3d_div_double(camera.vertical, 2)), w);

    return (camera);
}
