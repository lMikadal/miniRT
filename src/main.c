/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:31:57 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:31:59 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_init_info(t_info *info)
{
	info->ambient = NULL;
	info->camera = NULL;
	info->light = NULL;
	info->hittable_list = NULL;
	info->count_ambient = 1;
	info->count_camera = 1;
	info->count_light = 1;
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 2)
	{
		ft_init_info(&info);
		ft_parser(&info, av[1]);
		ft_write_map(av[1], &info);
	}
	else
		printf("Error argument\n");
	return (0);
}
