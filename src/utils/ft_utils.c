/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:33:11 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:33:12 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

static int	read_units(const char *s, int i, double *sum)
{
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		*sum = (*sum * 10) + (s[i++] - '0');
	return (i);
}

static double	ft_pow(double n, int p)
{
	double	sum;

	sum = 1.0;
	while (p-- > 0)
		sum *= n;
	return (sum);
}

static double	read_decimals(const char *str, int i, int d_power)
{
	double	sum;

	sum = 0.0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		sum += (double)(str[i++] - '0') / ft_pow(10, d_power++);
	return (sum);
}

double	ft_atod(const char *s, t_info *info)
{
	int		i;
	double	sum;
	int		m;

	if (ft_str_is_digit(s) == F)
		ft_error("Error is not digit", info);
	i = 0;
	sum = 0.0;
	m = 1;
	while (s[i] && ft_whitespace(s[i]))
		i++;
	if (s[i] == '-')
		m = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	i = read_units(s, i, &sum);
	if (s[i] == '.')
		sum += read_decimals(s, i + 1, 1);
	return (sum * m);
}
