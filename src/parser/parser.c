/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:27:00 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:27:02 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_insert_data(t_info *info, char **data)
{
	int	len;

	len = ft_strlen(data[0]);
	if (len == 1 && ft_strcmp(data[0], "A") == F)
		ft_set_ambient(info, data);
	else if (len == 1 && ft_strcmp(data[0], "C") == F)
		ft_set_camera(info, data);
	else if (len == 1 && ft_strcmp(data[0], "L") == F)
		ft_set_light(info, data);
	else if (len == 2 && ft_strcmp(data[0], "pl") == F)
		ft_set_plane(info, data);
	else if (len == 2 && ft_strcmp(data[0], "sp") == F)
		ft_set_sphere(info, data);
	else if (len == 2 && ft_strcmp(data[0], "cy") == F)
		ft_set_cylinder(info, data);
	else if (ft_strcmp(data[0], "\n"))
		ft_error("Error file", info);
}

void	ft_parser(t_info *info, char *file)
{
	int		open_fd;
	char	*data;
	char	**split_data;

	open_fd = open(file, O_RDONLY);
	if (open_fd < 0)
		printf("Error open file\n");
	while (1 && open_fd > 0)
	{
		data = get_next_line(open_fd);
		if (data == NULL)
			break ;
		split_data = ft_split_whitespace(data);
		if (split_data[0] != NULL)
			ft_insert_data(info, split_data);
		ft_free_2d(split_data);
		free(data);
	}
	close(open_fd);
}
