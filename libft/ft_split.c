/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:18:12 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/14 17:51:38 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sbstr(char const *s, size_t start, size_t len, char c)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = ft_calloc(len - start + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[start] == c)
		start++;
	while (start < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}

static size_t	ft_wcount(char const *s, char c)
{
	size_t	listsize;
	size_t	i;

	i = 0;
	listsize = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			listsize++;
		i++;
	}
	return (listsize);
}

static char	**freebuffer(char **buf, int j)
{
	while (j >= 0)
	{
		free(buf[j]);
		j--;
	}
	free(buf);
	return (NULL);
}

static void	ft_ite(int *i, int *start, char c, const char *s)
{
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	if (s[*i] != c)
		*start = *i;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**buffer;
	int		j;

	i = 0;
	j = -1;
	buffer = ft_calloc(ft_wcount(s, c) + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		ft_ite(&i, &start, c, s);
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				buffer[++j] = ft_sbstr (s, start, i + 1, c);
				if (!buffer[j])
					return (freebuffer(buffer, j - 1));
			}
			i++;
		}
	}
	return (buffer);
}
