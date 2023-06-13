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
// # include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"

# define HORIZON 1280
# define VERTICAL 720
# define ESC 53

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
	double	ratio;
	int		color;
}	t_ambient;

typedef struct s_camera
{
	double	point[3];
	double	vector[3];
	double	fov;
}	t_camera;

typedef struct s_light
{
	double	point[3];
	double	ratio;
}	t_light;

typedef struct s_sphere
{
	double			center[3];
	double			diameter;
	int				color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	double			point[3];
	double			vector[3];
	int				color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	double				point[3];
	double				vector[3];
	double				diameter;
	double				height;
	int					color;
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
}	t_info;

void	ft_free_2d(char **s);
char	**ft_split_whitespace(char const *s);
int		ft_strlen(char const *s);
int		ft_whitespace(char const c);
void	ft_error(char const *c);
void	ft_data(t_info *info, char *file);

// void	ft_write_map(char *name);

#endif
