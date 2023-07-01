/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:30:20 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/04 15:30:22 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "vec3.h"

# define T 1
# define F 0
# define HORIZON 1280
# define VERTICAL 720
# define ESC 53
# define PI 3.141592653589793

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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

typedef struct s_ambient
{
	double		ratio;
	t_rgb		color;
}	t_ambient;

typedef struct s_camera
{
	double	point[3];
	double	vector[3];
	double	fov;
}	t_camera;

typedef struct s_light
{
	double		point[3];
	double		ratio;
	t_rgb		color;
}	t_light;

typedef struct s_sphere
{
	double			center[3];
	double			diameter;
	t_rgb			color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	double			point[3];
	double			vector[3];
	t_rgb			color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	double				center[3];
	double				vector[3];
	double				diameter;
	double				height;
	t_rgb				color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_info
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	int			count_ambient;
	int			count_camera;
	int			count_light;
}	t_info;

// del
void ft_print_data(t_info *info);

void	ft_data(t_info *info, char *file);
void	ft_set_ambient(t_info *info, char **data);
void	ft_set_camera(t_info *info, char **data);
void	ft_set_light(t_info *info, char **data);
void	ft_set_plane(t_info *info, char **data);
void	ft_set_sphere(t_info *info, char **data);
void	ft_set_cylinder(t_info *info, char **data);
void	ft_error(const char *c, t_info *info);
void	ft_check_len_data(char **data, int len, t_info *info);
int		ft_whitespace(const char c);
int		ft_range_int(int min, int max, int num);
int		ft_range_double(double min, double max, double num);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_str_is_digit(const char *s);
void	ft_free_2d(char **s);
void	ft_free_info(t_info *info);
int		ft_count_word(const char *s, char c);
char	**ft_split_whitespace(const char *s);
char	**ft_split(const char *s, char c);
int		ft_strlen(const char *s);
double	ft_atod(const char *s, t_info *info);
int		ft_atoi(const char *s, t_info *info);
t_rgb	ft_set_color(const char *s, t_info *info);
void	ft_set_point(double *point, char *data, t_info *info);
void	ft_set_vector(double *vector, char *data, t_info *info);
int		ft_color(t_rgb color);

void	ft_mlx_pixel_put(t_mlx *ptr, int x, int y, int color);
void	ft_write_map(char *name, t_info *info);
void	render(t_mlx *mlx, t_info *info);

#endif
