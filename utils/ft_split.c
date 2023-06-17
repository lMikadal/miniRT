/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:34:03 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/17 17:34:05 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	ft_count_word_whitespace(const char *s)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (ft_whitespace(s[i]) == 0 && \
			(i == 0 || ft_whitespace(s[i - 1]) == 1))
			word++;
		i++;
	}
	return (word);
}

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_loc_string(const char *s, int start, int end)
{
	char	*m;
	int		i;

	i = 0;
	m = (char *)malloc((end - start + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	while (start < end)
		m[i++] = s[start++];
	m[i] = '\0';
	return (m);
}

char	**ft_split_whitespace(const char *s)
{
	char	**m;
	int		i;
	int		start;
	int		word;

	if (s == NULL)
		return (0);
	m = (char **)malloc((ft_count_word_whitespace(s) + 1) * sizeof(char *));
	if (m == NULL)
		return (0);
	i = 0;
	word = 0;
	while (i <= ft_strlen(s))
	{
		if (ft_whitespace(s[i]) == 0 \
			&& (i == 0 || ft_whitespace(s[i - 1]) == 1))
			start = i;
		if (i != 0 && ft_whitespace(s[i - 1]) == 0 \
			&& (ft_whitespace(s[i]) == 1 || s[i] == '\0'))
			m[word++] = ft_loc_string(s, start, i);
		i++;
	}
	m[word] = 0;
	return (m);
}

char	**ft_split(const char *s, char c)
{
	char	**m;
	int		i;
	int		start;
	int		word;

	if (s == NULL)
		return (0);
	m = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (m == NULL)
		return (0);
	i = 0;
	word = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (i != 0 && s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			m[word++] = ft_loc_string(s, start, i);
		i++;
	}
	m[word] = 0;
	return (m);
}
