/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:46:46 by pruangde          #+#    #+#             */
/*   Updated: 2023/09/18 15:44:58 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_INPUT_H
# define KEY_INPUT_H

int		cx_validkey(int key);
void	to_keyhall(int key, t_mlx *mlx);
void	err_key(int mode);
void	select_nextobj(t_mlx *mlx);
void	what_shape(t_ptr2obj *ptr2obj);

void	to_camera(int key, t_ptr2obj *ptr2obj, int *stat);
void	to_light(int key, t_light *lgt, int *stat);
void	to_ambient(int key, t_ambient *amb, int *stat);
void	to_shape(int key, t_ptr2obj *ptr2obj, int *stat);

// camera
void	cam_yaw_left(t_camera *cam);
void	cam_yaw_right(t_camera *cam);
void	rotatecam_updown(int key, t_ptr2obj *ptr, int *stat);
int		normal_vec_zx_zero(t_v3d cam);
void	reset_camera(t_camera *cam, int *stat);


// shape
//	sphere
int		to_sphere(int key, t_sphere *sp);


#endif
