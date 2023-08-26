/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:29:17 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:29:19 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "vec3.h"
# include "struct.h"
# include "parser.h"
# include "utils.h"
# include "ray.h"
# include "hit_record.h"
# include "camera.h"
# include "shape.h"
# include "render.h"
# include "mlx.h"
# include "mlx_int.h"

# define T 1
# define F 0
# define MIN 0.0
# define HORIZON 400
# define VERTICAL 225
# define ESC 53
# define PI 3.141592653589793
# define SP 1
# define PL 2
# define CY 3

void	ft_mlx_pixel_put(t_mlx *ptr, int x, int y, int color);
void	ft_write_map(char *name, t_info *info);
void	ft_print_data(t_info *info);

#endif
