/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:35:14 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 00:35:16 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_color(t_rgb color)
{
	int	c;

	c = color.r << 16;
	c += color.g << 8;
	c += color.b;
	return (c);
}

t_hittable_list	*ft_malloc_hittable(int name)
{
	t_hittable_list	*hittable;

	hittable = (t_hittable_list *)malloc(sizeof(t_hittable_list));
	if (hittable == NULL)
		return (NULL);
	hittable->type = name;
	hittable->next = NULL;
	return (hittable);
}
