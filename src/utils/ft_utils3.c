#include "minirt.h"

int ft_color(t_rgb color)
{
	int c;

	c = color.r << 16;
	c += color.g << 8;
	c += color.b;
	return (c);
}