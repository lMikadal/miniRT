/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:30:43 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:32:03 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_set_sphere2(t_sphere **sphere, char **data, t_info *info)
{
	sphere[0] = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return ;
	ft_set_point(&(sphere[0]->coordinates_center), data[1], info);
	sphere[0]->radius = ft_atod(data[2], info) / 2;
	sphere[0]->color = ft_set_color(data[3], info);
}

void	ft_set_sphere(t_info *info, char **data)
{
	t_hittable_list	*tmp;

	ft_check_len_data(data, 4, info);
	if (info->hittable_list == NULL)
	{
		info->hittable_list = ft_malloc_hittable(SP);
		ft_set_sphere2(&(info->hittable_list->sphere), data, info);
	}
	else
	{
		tmp = info->hittable_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_malloc_hittable(SP);
		ft_set_sphere2(&(tmp->next->sphere), data, info);
	}
}

static void	ft_set_cylinder2(t_cylinder **cylinder, char **data, t_info *info)
{
	cylinder[0] = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return ;
	ft_set_point(&(cylinder[0]->coordinates_center), data[1], info);
	ft_set_vector(&(cylinder[0]->normalized_vector), data[2], info);
	cylinder[0]->normalized_vector = \
		v3d_unit_vec(cylinder[0]->normalized_vector);
	cylinder[0]->radius = ft_atod(data[3], info) / 2;
	cylinder[0]->height = ft_atod(data[4], info);
	cylinder[0]->color = ft_set_color(data[5], info);
}

void	ft_set_cylinder(t_info *info, char **data)
{
	t_hittable_list	*tmp;

	ft_check_len_data(data, 6, info);
	if (info->hittable_list == NULL)
	{
		info->hittable_list = ft_malloc_hittable(CY);
		ft_set_cylinder2(&(info->hittable_list->cylinder), data, info);
	}
	else
	{
		tmp = info->hittable_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_malloc_hittable(CY);
		ft_set_cylinder2(&(tmp->next->cylinder), data, info);
	}
}
