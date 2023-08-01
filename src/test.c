#include "minirt.h"

// del
void ft_print_data(t_info *info)
{
	t_hittable_list *tmp;

	if (info->ambient != NULL)
	{
		printf("ambient\n");
		printf("ratio: %lf\n", info->ambient->ratio);
		printf("color: %d, %d, %d, %d\n", info->ambient->color.r, info->ambient->color.g, info->ambient->color.b, ft_color(info->ambient->color));
		printf("--------------------------\n");
	}
	if (info->camera != NULL)
	{
		printf("camera\n");
		printf("point: %lf %lf %lf\n", info->camera->coordinates_point.x, info->camera->coordinates_point.y, info->camera->coordinates_point.z);
		printf("vector: %lf %lf %lf\n", info->camera->normalized_vector.x, info->camera->normalized_vector.y, info->camera->normalized_vector.z);
		printf("fov: %lf\n", info->camera->fov);
		printf("--------------------------\n");
	}
	if (info->light != NULL)
	{
		printf("light\n");
		printf("point: %lf %lf %lf\n", info->light->coordinates_point.x, info->light->coordinates_point.y, info->light->coordinates_point.z);
		printf("ratio: %lf\n", info->light->ratio);
		printf("color: %d, %d, %d\n", info->light->color.r, info->light->color.g, info->light->color.b);
		printf("--------------------------\n");
	}
	tmp = info->hittable_list;
	while (tmp != NULL)
	{
		if (tmp->type == PL)
		{
			printf("plane\n");
			printf("point: %lf %lf %lf\n", tmp->plane->coordinates_point.x, tmp->plane->coordinates_point.y, tmp->plane->coordinates_point.z);
			printf("vector: %lf %lf %lf\n", tmp->plane->normalized_vector.x, tmp->plane->normalized_vector.y, tmp->plane->normalized_vector.z);
			printf("color: %d, %d, %d\n", tmp->plane->color.r, tmp->plane->color.g, tmp->plane->color.b);
		}
		else if (tmp->type == SP)
		{
			printf("sphere\n");
			printf("center: %lf %lf %lf\n", tmp->sphere->coordinates_center.x, tmp->sphere->coordinates_center.y, tmp->sphere->coordinates_center.z);
			printf("diameter: %lf\n", tmp->sphere->diameter);
			printf("color: %d, %d, %d\n", tmp->sphere->color.r, tmp->sphere->color.g, tmp->sphere->color.b);
		}
		else if (tmp->type == CY)
		{
			printf("cylinder\n");
			printf("point: %lf %lf %lf\n", tmp->cylinder->coordinates_center.x, tmp->cylinder->coordinates_center.y, tmp->cylinder->coordinates_center.z);
			printf("vector: %lf %lf %lf\n", tmp->cylinder->normalized_vector.x, tmp->cylinder->normalized_vector.y, tmp->cylinder->normalized_vector.z);
			printf("diameter: %lf\n", tmp->cylinder->diameter);
			printf("height: %lf\n", tmp->cylinder->height);
			printf("color: %d, %d, %d\n", tmp->cylinder->color.r, tmp->cylinder->color.g, tmp->cylinder->color.b);
		}
		printf("--------------------------\n");
		tmp = tmp->next;
	}
}
