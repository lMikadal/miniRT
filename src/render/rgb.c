/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:33:14 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/17 08:20:18 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cx_rgb_limit(t_rgb *a)
{
	if (a->r > 255)
		a->r = 255;
	else if (a->r < 0)
		a->r = 0;
	if (a->g > 255)
		a->g = 255;
	else if (a->g < 0)
		a->g = 0;
	if (a->b > 255)
		a->b = 255;
	else if (a->b < 0)
		a->b = 0;
}

t_rgb	rgb_plus(t_rgb a, t_rgb b)
{
	t_rgb	rgb;

	rgb.r = a.r + b.r;
	rgb.g = a.g + b.g;
	rgb.b = a.b + b.b;
	cx_rgb_limit(&rgb);
	return (rgb);
}

t_rgb	rgb_minus(t_rgb a, t_rgb b)
{
	t_rgb	rgb;

	rgb.r = a.r - b.r;
	rgb.g = a.g - b.g;
	rgb.b = a.b - b.b;
	cx_rgb_limit(&rgb);
	return (rgb);
}

t_rgb	rgb_create(double r, double g, double b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	rgb_ratio(t_rgb a, double ratio)
{
	t_rgb	rgb;

	rgb.r = a.r * ratio;
	rgb.g = a.g * ratio;
	rgb.b = a.b * ratio;
	return (rgb);
}
