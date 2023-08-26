/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:29:07 by pmikada           #+#    #+#             */
/*   Updated: 2023/08/27 03:29:11 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	ft_parser(t_info *info, char *file);
void	ft_set_ambient(t_info *info, char **data);
void	ft_set_camera(t_info *info, char **data);
void	ft_set_light(t_info *info, char **data);
void	ft_set_plane(t_info *info, char **data);
void	ft_set_sphere(t_info *info, char **data);
void	ft_set_cylinder(t_info *info, char **data);

#endif
