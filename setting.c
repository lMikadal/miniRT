#include "miniRT.h"

static void	ft_set_ambient(t_info *info, char **data)
{
	t_ambient	*ambient;
	double		ratio;
	int			color;

	ft_check_len_data(data, 3);
	ambient = (t_ambient *)malloc(sizeof(t_ambient *));
	if (ambient == NULL)
		return ;
	ratio = ft_atod(data[1]);
	if (ft_range_double(0.0, 1.0, ratio) == 0)
		ft_error("Error ambient");
	color = ft_set_color(data[2]);
	ambient->ratio = ratio;
	ambient->color = color;
	info->ambient = ambient;
}

static void ft_insert_data(t_info *info, char **data)
{
	int	len;

	len = ft_strlen(data[0]);
	if (len == 1 && ft_strcmp(data[0], "A") == F)
		ft_set_ambient(info, data);
	else if (len == 1 && ft_strcmp(data[0], "C") == F)
		printf("C\n");
	else if (len == 1 && ft_strcmp(data[0], "L") == F)
		printf("L\n");
	else if (len == 2 && ft_strcmp(data[0], "pl") == F)
		printf("pl\n");
	else if (len == 2 && ft_strcmp(data[0], "sp") == F)
		printf("sp\n");
	else if (len == 2 && ft_strcmp(data[0], "cy") == F)
		printf("cy\n");
	else if (ft_strcmp(data[0], "\n"))
		ft_error("Error file");
}

void	ft_data(t_info *info, char *file)
{
	int		open_fd;
	char	*data;
	char	**split_data;
	
	open_fd = open(file, O_RDONLY);
	if (open_fd < 0)
		ft_error("Error open file");
	while (1 && open_fd > 0)
	{
		data = get_next_line(open_fd);
		if (data == NULL)
			break ;
		split_data = ft_split_whitespace(data);
		if (split_data[0] != NULL)
			ft_insert_data(info, split_data);
		ft_free_2d(split_data);
		free(data);
	}
}