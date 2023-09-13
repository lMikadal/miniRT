/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:28:59 by pmikada           #+#    #+#             */
/*   Updated: 2023/09/13 06:42:56 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	render(t_mlx *mlx);

// all rgb
t_rgb	rgb_plus(t_rgb a, t_rgb b);
t_rgb	rgb_create(double r, double g, double b);
t_rgb	rgb_ratio(t_rgb a, double ratio);

#endif
