/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:28:12 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:30:22 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_set_ambient(t_info *info, char **data)
{
	ft_check_len_data(data, 3, info);
	info->count_ambient -= 1;
	if (info->count_ambient < 0)
		ft_error("Error ambient more than one", info);
	info->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (info->ambient == NULL)
		return;
	info->ambient->ratio = ft_atod(data[1], info);
	if (ft_range_double(0.0, 1.0, info->ambient->ratio) == F)
		ft_error("Error ambient", info);
	info->ambient->color = ft_set_color(data[2], info);
}

void ft_set_camera(t_info *info, char **data)
{
	ft_check_len_data(data, 4, info);
	info->count_camera -= 1;
	if (info->count_camera < 0)
		ft_error("Error camera more than one", info);
	info->camera = (t_camera *)malloc(sizeof(t_camera));
	if (info->camera == NULL)
		return;
	ft_set_point(info->camera->point, data[1], info);
	ft_set_vector(info->camera->vector, data[2], info);
	info->camera->fov = ft_atod(data[3], info);
	if (ft_range_int(0, 180, info->camera->fov) == F)
		ft_error("Error camera", info);
}

void ft_set_light(t_info *info, char **data)
{
	ft_check_len_data(data, 4, info);
	info->count_light -= 1;
	if (info->count_light < 0)
		ft_error("Error light more than one", info);
	info->light = (t_light *)malloc(sizeof(t_light));
	if (info->light == NULL)
		return;
	ft_set_point(info->light->point, data[1], info);
	info->light->ratio = ft_atod(data[2], info);
	if (ft_range_double(0.0, 1.0, info->light->ratio) == F)
		ft_error("Error light", info);
	info->light->color = ft_set_color(data[3], info);
}

static void ft_set_plane2(t_plane **plane, char **data, t_info *info)
{
	plane[0] = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return;
	ft_set_point(plane[0]->point, data[1], info);
	ft_set_vector(plane[0]->vector, data[2], info);
	plane[0]->color = ft_set_color(data[3], info);
	plane[0]->next = NULL;
}

void ft_set_plane(t_info *info, char **data)
{
	t_plane *tmp;

	ft_check_len_data(data, 4, info);
	if (info->plane == NULL)
		ft_set_plane2(&info->plane, data, info);
	else
	{
		tmp = info->plane;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_set_plane2(&tmp->next, data, info);
	}
}
