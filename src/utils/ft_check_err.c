/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:34:38 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:34:40 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error(const char *c, t_info *info)
{
	printf("%s\n", c);
	ft_free_info(info);
	exit(1);
}

void	ft_check_len_data(char **data, int len, t_info *info)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	if (i != len)
		ft_error("Error data not match", info);
}
