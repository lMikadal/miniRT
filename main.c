/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:24:31 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/04 15:24:34 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_init_info(t_info *info)
{
	info->ambient = NULL;
	info->camera = NULL;
	info->light = NULL;
	info->sphere = NULL;
	info->plane = NULL;
	info->cylinder = NULL;
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 2)
	{
		ft_init_info(&info);
		ft_data(&info, av[1]);
	}
	else
		ft_error("Error");
	return (0);
}
