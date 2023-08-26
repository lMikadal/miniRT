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