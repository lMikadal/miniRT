#include "miniRT.h"

static void ft_insert_data(t_info *info, char **data)
{
	if (data[0][0] == 'A')
		printf("A\n");
	else if (data[0][0] == 'C')
		printf("C\n");
	else if (data[0][0] == 'L')
		printf("L\n");
	else if (data[0][0] == 'p' && data[0][1] == 'l')
		printf("pl\n");
	else if (data[0][0] == 's' && data[0][1] == 'p')
		printf("sp\n");
	else if (data[0][0] == 'c' && data[0][1] == 'y')
		printf("cy\n");
	else if (data[0][0] != '\n')
		ft_error("Error\n");
}

void	ft_data(t_info *info, char *file)
{
	int		open_fd;
	char	*data;
	char	**split_data;
	
	open_fd = open(file, O_RDONLY);
	if (open_fd < 0)
		ft_error("Error");
	while (1 && open_fd > 0)
	{
		data = get_next_line(open_fd);
		if (data == NULL)
			break ;
		split_data = ft_split_whitespace(data);
		ft_insert_data(info, split_data);
		ft_free_2d(split_data);
		free(data);
	}
}