#include "../miniRT.h"

int	ft_whitespace(const char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (T);
	return (F);
}

int	ft_range_int(int min, int max, int num)
{
	if (num >= min && num <= max)
		return (T);
	return (F);
}

int	ft_range_double(double min, double max, double num)
{
	if (num >= min && num <= max)
		return (T);
	return (F);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (T);
		i++;
	}
	return (F);
}

int	ft_str_is_digit(const char *s)
{
	int	i;
	int	single;
	int	point;

	i = -1;
	single = 1;
	point = 1;
	if (s == NULL)
		return (F);
	if (s[0] == '-' || s[0] == '+')
	{
		single--;
		i++;
	}
	while (s[++i])
	{
		if (s[i] == '.')
			point--;	
		if (point < 0 || single < 0)
			return (F);
		else if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
			return (F);
	}
	return (T);
}