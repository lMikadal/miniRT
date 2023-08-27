/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:28:23 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:28:25 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct s_camera
{
	t_v3d	coordinates_point;
	t_v3d	normalized_vector;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_v3d	coordinates_point;
	double	ratio;
	t_rgb	color;
}	t_light;

typedef struct s_sphere
{
	t_v3d	coordinates_center;
	double	radius;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	t_v3d	coordinates_point;
	t_v3d	normalized_vector;
	t_rgb	color;
}	t_plane;

typedef struct s_cylinder
{
	t_v3d	coordinates_center;
	t_v3d	normalized_vector;
	double	radius;
	double	height;
	t_rgb	color;
}	t_cylinder;

typedef struct s_hittable_list
{
	int						type;
	t_sphere				*sphere;
	t_plane					*plane;
	t_cylinder				*cylinder;
	struct s_hittable_list	*next;
}	t_hittable_list;

typedef struct s_info
{
	t_ambient		*ambient;
	t_camera		*camera;
	t_light			*light;
	t_hittable_list	*hittable_list;
	int				count_ambient;
	int				count_camera;
	int				count_light;
}	t_info;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_mlx;

#endif
