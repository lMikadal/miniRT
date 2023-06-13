#include "../miniRT.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_whitespace(char const c)
{
	if (c == ' ' || c == '\t' || c == '\v' \
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	ft_error(char const *c)
{
	printf("%s\n", c);
}