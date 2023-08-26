#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_ca
{
    t_v3d	origin;
    t_v3d	horizontal;
    t_v3d	vertical;
    t_v3d	l_l_c;
}	t_ca;

t_ray	get_ray(double u, double v, t_ca camera);
t_ca	create_camera(t_v3d lookfrom, t_v3d lookat, t_v3d vup, double fov, double aspect_ratio);

#endif