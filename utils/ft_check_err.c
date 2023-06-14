#include "miniRT.h"

void	ft_error(const char *c)
{
	printf("%s\n", c);
	exit(0);
}

void	ft_check_len_data(char **data, int len)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	if (i != len)
		ft_error("Error data not match");	
}