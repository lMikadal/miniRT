/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:51:40 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/26 23:51:42 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

typedef struct s_hit_record
{
	t_v3d	p;
	t_v3d	normal;
	double	t;
	int		front_face;
	int		type;
	t_rgb	color;
}	t_hit_record;

int	hittable_list(t_ray r, t_hit_record *rec, t_info *info);

#endif
