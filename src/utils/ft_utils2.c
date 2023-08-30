/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:42:44 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:42:45 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:32:54 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:32:55 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_atoi(const char *s, t_info *info)
{
	int	i;
	int	m;
	int	sum;

	if (ft_str_is_digit(s) == F)
		ft_error("Error is not digit", info);
	i = 0;
	while (ft_whitespace(s[i]))
		i++;
	m = 1;
	if (s[i] == '-')
		m = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	sum = 0;
	while (s[i] >= '0' && s[i] <= '9')
		sum = (sum * 10) + (s[i++] - '0');
	return (sum * m);
}

static int	ft_check_str(const char *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (data[++i])
	{
		if (data[i] == ',')
			count++;
	}
	if (count != 2)
		return (F);
	return (T);
}

t_rgb	ft_set_color(const char *s, t_info *info)
{
	t_rgb	color;
	char	**split_color;
	int		i;

	split_color = ft_split(s, ',');
	i = -1;
	while (split_color[++i])
	{
		if (ft_str_is_digit(split_color[i]) == F || \
			ft_range_double(0, 255, ft_atod(split_color[i], info)) == F)
		{
			ft_free_2d(split_color);
			ft_error("Error color", info);
		}
	}
	if (i != 3 || ft_check_str(s) == F)
	{
		ft_free_2d(split_color);
		ft_error("Error color size", info);
	}
	color.r = ft_atoi(split_color[0], info);
	color.g = ft_atoi(split_color[1], info);
	color.b = ft_atoi(split_color[2], info);
	ft_free_2d(split_color);
	return (color);
}

void	ft_set_point(t_v3d *point, char *data, t_info *info)
{
	char	**split_data;
	int		i;

	split_data = ft_split(data, ',');
	i = -1;
	while (split_data[++i])
	{
		if (ft_str_is_digit(split_data[i]) == F)
		{
			ft_free_2d(split_data);
			ft_error("Error point", info);
		}
	}
	if (i != 3 || ft_check_str(data) == F)
	{
		ft_free_2d(split_data);
		ft_error("Error point size", info);
	}
	point->x = ft_atod(split_data[0], info);
	point->y = ft_atod(split_data[1], info);
	point->z = ft_atod(split_data[2], info);
	ft_free_2d(split_data);
}

void	ft_set_vector(t_v3d *vector, char *data, t_info *info)
{
	char	**split_data;
	int		i;

	split_data = ft_split(data, ',');
	i = -1;
	while (split_data[++i])
	{
		if (ft_str_is_digit(split_data[i]) == F || \
			ft_range_double(-1.0, 1.0, ft_atod(split_data[i], info)) == F)
		{
			ft_free_2d(split_data);
			ft_error("Error vector", info);
		}
	}
	if (i != 3 || ft_check_str(data) == F)
	{
		ft_free_2d(split_data);
		ft_error("Error vector size", info);
	}
	vector->x = ft_atod(split_data[0], info);
	vector->y = ft_atod(split_data[1], info);
	vector->z = ft_atod(split_data[2], info);
	ft_free_2d(split_data);
}
