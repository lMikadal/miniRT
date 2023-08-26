/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:36:06 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:36:08 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_2d(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	ft_free_info(t_info *info)
{
	if (info->ambient != NULL)
		free(info->ambient);
	if (info->camera != NULL)
		free(info->camera);
	if (info->light != NULL)
		free(info->light);
}
