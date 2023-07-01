#include "miniRT.h"

double	deg2rad(double deg)
{
	return (deg * PI / 180);
}

void	multVecMatrix(t_v3d *s, t_v3d *ori)
{
	double	a;
	double	b;
	double	c;
	double	w;

	a = (s->x * 1) + (s->y * 0) + (s->z * 0) + 0;
	b = (s->x * 0) + (s->y * 1) + (s->z * 0) + 0;
	c = (s->x * 0) + (s->y * 0) + (s->z * 1) + 0;
	w = (s->x * 0) + (s->y * 0) + (s->z * 0) + 1;

	ori->x = a / w;
	ori->y = b / w;
	ori->z = c / w;
}

void	multDirMatrix(t_v3d *s, t_v3d *ori)
{
	double	a;
	double	b;
	double	c;

	a = (s->x * 1) + (s->y * 0) + (s->z * 0);
	b = (s->x * 0) + (s->y * 1) + (s->z * 0);
	c = (s->x * 0) + (s->y * 0) + (s->z * 1);

	ori->x = a;
	ori->y = b;
	ori->z = c;
}

void	render(t_mlx *mlx, t_info *info)
{
	double	scale;
	double	imageAspecRatio;
	double	x;
	double	y;
	int		i;
	int		j;
	t_v3d	tmp;
	t_v3d	ori;
	t_v3d	dir;

	scale = tan(deg2rad(info->camera->fov * 0.5));
	imageAspecRatio = HORIZON / (double)VERTICAL;
	v3d_create(&tmp, 0, 0, 0);
	multVecMatrix(&tmp, &ori);
	i = -1;
	while(++i < VERTICAL)
	{
		j = -1;
		while(++j < HORIZON)
		{
			x = (2 * (i + 0.5) / (double)HORIZON - 1) * imageAspecRatio * scale;
			y = (1 - 2 * (j + 0.5) / (double)VERTICAL) * scale;
			v3d_create(&tmp, x, y, -1);
			multDirMatrix(&tmp, &dir);
			dir = v3d_normalize(dir);
			ft_mlx_pixel_put(mlx, j, i, 16777215 - j);
		}
	}
}