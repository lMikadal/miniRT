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

#include "miniRT.h"

static void	ft_set_sphere2(t_sphere **sphere, char **data, t_info *info)
{
	sphere[0] = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return ;
	ft_set_point(sphere[0]->center, data[1], info);
	sphere[0]->diameter = ft_atod(data[2], info);
	sphere[0]->color = ft_set_color(data[3], info);
	sphere[0]->next = NULL;
}

void	ft_set_sphere(t_info *info, char **data)
{
	t_sphere	*tmp;

	ft_check_len_data(data, 4, info);
	if (info->sphere == NULL)
		ft_set_sphere2(&info->sphere, data, info);
	else
	{
		tmp = info->sphere;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_set_sphere2(&tmp->next, data, info);
	}
}

static void	ft_set_cylinder2(t_cylinder **cylinder, char **data, t_info *info)
{
	cylinder[0] = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return ;
	ft_set_point(cylinder[0]->center, data[1], info);
	ft_set_vector(cylinder[0]->vector, data[2], info);
	cylinder[0]->diameter = ft_atod(data[3], info);
	cylinder[0]->height = ft_atod(data[4], info);
	cylinder[0]->color = ft_set_color(data[5], info);
	cylinder[0]->next = NULL;
}

void	ft_set_cylinder(t_info *info, char **data)
{
	t_cylinder	*tmp;

	ft_check_len_data(data, 6, info);
	if (info->cylinder == NULL)
		ft_set_cylinder2(&info->cylinder, data, info);
	else
	{
		tmp = info->cylinder;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_set_cylinder2(&tmp->next, data, info);
	}
}
