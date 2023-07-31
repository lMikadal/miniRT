#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_rgb
{
	int r;
	int g;
	int b;
} t_rgb;

typedef struct s_ambient
{
	double ratio;
	t_rgb color;
} t_ambient;

typedef struct s_camera
{
	double point[3];
	double vector[3];
	double fov;
} t_camera;

typedef struct s_light
{
	double point[3];
	double ratio;
	t_rgb color;
} t_light;

typedef struct s_sphere
{
	double center[3];
	double diameter;
	t_rgb color;
	struct s_sphere *next;
} t_sphere;

typedef struct s_plane
{
	double point[3];
	double vector[3];
	t_rgb color;
	struct s_plane *next;
} t_plane;

typedef struct s_cylinder
{
	double center[3];
	double vector[3];
	double diameter;
	double height;
	t_rgb color;
	struct s_cylinder *next;
} t_cylinder;

typedef struct s_hittable_list
{
	int type;
	t_sphere *sphere;
	t_plane *plane;
	t_cylinder *cylinder;
	struct s_hittable_list *next;
} t_hittable_list;

typedef struct s_info
{
	t_ambient *ambient;
	t_camera *camera;
	t_light *light;
	t_sphere *sphere;
	t_plane *plane;
	t_cylinder *cylinder;
	t_hittable_list *hittable_list;
	int count_ambient;
	int count_camera;
	int count_light;
} t_info;

typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int bits;
	int line;
	int endian;
} t_mlx;

#endif