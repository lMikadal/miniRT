#include "miniRT.h"

void	ft_data(t_info *info, char *file)
{
	int		open_fd;
	char	*data;
	char	**split;
	
	open_fd = open(file, O_RDONLY);
int i = 0;
	while (1)
	{
		data = get_next_line(open_fd);
		if (data == NULL)
			break ;
		split = ft_split(data, ' ');
int	j = -1;
while (split[++j])
	printf("split[%d][%d] = |%s|\n", i, j, split[j]);
i++;
		ft_free_2d(split);
		free(data);
	}
	
}