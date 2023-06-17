#include "../miniRT.h"

void	ft_free_2d(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	ft_free_info(t_info *info)
{
	t_sphere	*tmp_sphere;
	t_plane		*tmp_plane;
	t_cylinder		*tmp_cylinder;

	if (info->ambient != NULL)
		free(info->ambient);
	if (info->camera != NULL)
		free(info->camera);
	if (info->light != NULL)
		free(info->light);
	if (info->sphere != NULL)
	{
		while(info->sphere)
		{
			tmp_sphere = info->sphere->next;
			free(info->sphere);
			info->sphere = tmp_sphere;	
		}
	}
	if (info->plane != NULL)
	{
		while(info->plane)
		{
			tmp_plane = info->plane->next;
			free(info->plane);
			info->plane = tmp_plane;	
		}
	}
	if (info->cylinder != NULL)
	{
		while(info->cylinder)
		{
			tmp_cylinder = info->cylinder->next;
			free(info->cylinder);
			info->cylinder = tmp_cylinder;	
		}
	}
}