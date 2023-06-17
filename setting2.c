#include "miniRT.h"

void	ft_set_ambient(t_info *info, char **data)
{
	t_ambient	*ambient;
	double		ratio;
	int			color;

	ft_check_len_data(data, 3, info);
	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (ambient == NULL)
		return ;
	ratio = ft_atod(data[1], info);
	if (ft_range_double(0.0, 1.0, ratio) == F)
		ft_error("Error ambient", info);
	color = ft_set_color(data[2], info);
	ambient->ratio = ratio;
	ambient->color = color;
	info->ambient = ambient;
}

void	ft_set_camera(t_info *info, char **data)
{
	t_camera	*camera;
	double		fov;

    ft_check_len_data(data, 4, info);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		return ;
	ft_set_point(camera->point, data[1], info);
	ft_set_vector(camera->vector, data[2], info);
	fov = ft_atod(data[3], info);
	if (ft_range_int(0, 180, fov) == F)
		ft_error("Error camera", info);
	camera->fov = fov;
	info->camera = camera;
}

void	ft_set_light(t_info *info, char **data)
{
	t_light	*light;
	double	ratio;

    ft_check_len_data(data, 4, info);
	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return ;
	ft_set_point(light->point, data[1], info);
	ratio = ft_atod(data[2], info);
	if (ft_range_double(0.0, 1.0, ratio) == F)
		ft_error("Error light", info);
	light->ratio = ratio;
    light->color = ft_set_color(data[3], info);
	info->light = light;
}

static void	ft_set_plane2(t_plane **plane, char **data, t_info *info)
{
	plane[0] = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return ;
	ft_set_point(plane[0]->point, data[1], info);
	ft_set_vector(plane[0]->vector, data[2], info);
	plane[0]->color = ft_set_color(data[3], info);
	plane[0]->next = NULL;
}

void	ft_set_plane(t_info *info, char **data)
{
	t_plane	*tmp;

    ft_check_len_data(data, 4, info);
	if (info->plane == NULL)
		ft_set_plane2(&info->plane, data, info);
	else
	{
		tmp = info->plane;
		while(tmp->next != NULL)
			tmp = tmp->next;
		ft_set_plane2(&tmp->next, data, info);
	}
}