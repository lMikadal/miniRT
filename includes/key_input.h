/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:46:46 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/22 13:57:31 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_INPUT_H
# define KEY_INPUT_H

typedef struct s_v2d
{
	double	x;
	double	y;
}			t_v2d;

typedef struct s_r2d
{
	t_v2d	origin;
	t_v2d	direction;
}			t_r2d;

// vec 2D
double	v2d_dot(t_v2d a, t_v2d b);
double	v2d_length(t_v2d v);
t_v2d	v2d_create(double x, double y);
t_v2d	v2d_rotate(t_v2d v, double degree);


int		cx_validkey(int key);
void	to_keyhall(int key, t_mlx *mlx);
void	err_key(int mode);
void	select_nextobj(t_mlx *mlx);
void	what_shape(t_ptr2obj *ptr2obj);

void	to_camera(int key, t_ptr2obj *ptr2obj, int *stat);
void	to_light(int key, t_light *lgt, int *stat);
void	to_ambient(int key, t_ambient *amb, int *stat);
void	to_shape(int key, t_ptr2obj *ptr2obj, int *stat);

int		to_sphere(int key, t_sphere *sp);
int		to_plane(int key, t_plane *pl);
int		to_cylinder(int key, t_cylinder *cy);

// camera
void	cam_yaw_left(t_camera *cam);
void	cam_yaw_right(t_camera *cam);
void	reset_camera(t_camera *cam);

// plane

// cylinder
void	cy_rotate(int key, t_cylinder *cy);

#endif
