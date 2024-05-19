/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:24:52 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/15 17:29:38 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	start;

	if (s1 == NULL || s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	i = 0;
	len = ft_strlen(s1) - 1;
	while (ft_search_set(s1[start], set) && s1[start] && set)
		start++;
	while (ft_search_set(s1[len], set) && len > start)
		len--;
	str = ft_calloc((len - start + 2), sizeof(char));
	if (!str)
		return (NULL);
	while (start <= len)
		str[i++] = s1[start++];
	return (str);
}
