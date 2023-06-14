#include "../miniRT.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	m;
	int	sum;

	if (ft_str_is_digit(s) == F)
		ft_error("Error is not digit");
	i = 0;
	while (ft_whitespace(s[i]))
		i++;
	m = 1;
	if (s[i] == '-')
		m = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	sum = 0;
	while (s[i] >= '0' && s[i] <= '9')
		sum = (sum * 10) + (s[i++] - '0');
	return (sum * m);
}

int	ft_set_color(const char *s)
{
	int		color;
	char	**split_color;
	int		i;

	split_color = ft_split(s, ',');
	i = -1;
	while (split_color[++i])
	{
		if (ft_str_is_digit(split_color[i]) == F || \
			ft_range_double(0, 255, ft_atod(split_color[i])) == F)
		{
			ft_free_2d(split_color);
			ft_error("Error color");
		}
	}
	color = ft_atoi(split_color[0]) << 16;
	color += ft_atoi(split_color[1]) << 8;
	color += ft_atoi(split_color[2]);
	ft_free_2d(split_color);
	return (color);
}