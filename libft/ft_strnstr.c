/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:00:31 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/15 17:29:31 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_len;
	size_t	strlen;
	size_t	i;
	size_t	j;

	if (*find == 0)
		return ((char *) str);
	i = 0;
	strlen = ft_strlen(str);
	find_len = ft_strlen(find) - 1;
	while (*str && i < len)
	{
		j = 0;
		while (find_len < strlen && str[i + j] == find[j] && i + j < len)
		{
			if (j == find_len)
				return ((char *) &str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
