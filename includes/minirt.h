#ifndef MINIRT_H
#define MINIRT_H

#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "get_next_line.h"
#include "struct.h"
#include "parser.h"
#include "utils.h"
#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "render.h"
#include "mlx.h"
#include "mlx_int.h"

#define T 1
#define F 0
#define HORIZON 400
#define VERTICAL 225
#define ESC 53
#define PI 3.141592653589793

void ft_mlx_pixel_put(t_mlx *ptr, int x, int y, int color);
void ft_write_map(char *name, t_info *info);

// test
void ft_print_data(t_info *info);

#endif