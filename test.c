#include "miniRT.h"

// del
void ft_print_data(t_info *info)
{
	t_sphere	*tmp_sphere;
	t_plane		*tmp_plane;
	t_cylinder	*tmp_cylinder;

	if (info->ambient != NULL) {
		printf("ambient\n");
		printf("ratio: %lf\n", info->ambient->ratio);
		printf("color: %d, %d, %d, %d\n", info->ambient->color.r, info->ambient->color.g, info->ambient->color.b, ft_color(info->ambient->color));
		printf("--------------------------\n");
	}
	if (info->camera != NULL) {
		printf("camera\n");
		printf("point: %lf %lf %lf\n", info->camera->point[0], info->camera->point[1], info->camera->point[2]);
		printf("vector: %lf %lf %lf\n", info->camera->vector[0], info->camera->vector[1], info->camera->vector[2]);
		printf("fov: %lf\n", info->camera->fov);
		printf("--------------------------\n");
	}
	if (info->light != NULL) {
		printf("light\n");
		printf("point: %lf %lf %lf\n", info->light->point[0], info->light->point[1], info->light->point[2]);
		printf("ratio: %lf\n", info->light->ratio);
		printf("color: %d, %d, %d\n", info->light->color.r, info->light->color.g, info->light->color.b);
		printf("--------------------------\n");
	}
	if (info->sphere != NULL) {
		tmp_sphere = info->sphere;

		printf("sphere\n");
		while (tmp_sphere != NULL) {
			printf("center: %lf %lf %lf\n", tmp_sphere->center[0], tmp_sphere->center[1], tmp_sphere->center[2]);
			printf("diameter: %lf\n", tmp_sphere->diameter);
			printf("color: %d, %d, %d\n", tmp_sphere->color.r, tmp_sphere->color.g, tmp_sphere->color.b);
			tmp_sphere = tmp_sphere->next;
		}
		printf("--------------------------\n");
	}
	if (info->plane != NULL) {
		tmp_plane = info->plane;

		printf("plane\n");
		while (tmp_plane != NULL) {
			printf("point: %lf %lf %lf\n", tmp_plane->point[0], tmp_plane->point[1], tmp_plane->point[2]);
			printf("vector: %lf %lf %lf\n", tmp_plane->vector[0], tmp_plane->vector[1], tmp_plane->vector[2]);
			printf("color: %d, %d, %d\n", tmp_plane->color.r, tmp_plane->color.g, tmp_plane->color.b);
			tmp_plane = tmp_plane->next;
		}
		printf("--------------------------\n");
	}
	if (info->cylinder != NULL) {
		tmp_cylinder = info->cylinder;

		printf("cylinder\n");
		while(tmp_cylinder != NULL) {
			printf("point: %lf %lf %lf\n", tmp_cylinder->center[0],tmp_cylinder->center[1],tmp_cylinder->center[2]);
			printf("vector: %lf %lf %lf\n", tmp_cylinder->vector[0],tmp_cylinder->vector[1],tmp_cylinder->vector[2]);
			printf("diameter: %lf\n", tmp_cylinder->diameter);
			printf("height: %lf\n", tmp_cylinder->height);
			printf("color: %d, %d, %d\n", tmp_cylinder->color.r, tmp_cylinder->color.g, tmp_cylinder->color.b);
			tmp_cylinder = tmp_cylinder->next;
		}
		printf("--------------------------\n");
	}
}
