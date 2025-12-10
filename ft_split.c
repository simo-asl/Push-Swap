/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:12:54 by mel-asla          #+#    #+#             */
/*   Updated: 2025/10/18 16:44:04 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 1;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_extract(const char *s, char c)
{
	size_t	len;
	char	*d;

	len = ft_len(s, c);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s, len + 1);
	return (d);
}

static int	ft_fill(char **res, const char *s, char c, size_t count)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = ft_extract(&s[i], c);
		if (!res[j])
		{
			while (j > 0)
			{
				j--;
				free(res[j]);
			}
			return (0);
		}
		i += ft_len(&s[i], c);
		j++;
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!ft_fill(res, s, c, count))
	{
		free(res);
		return (NULL);
	}
	return (res);
}
