/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:52:44 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/15 17:29:34 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	charc;

	charc = c;
	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == charc)
		{
			return (&str[i]);
		}
		i--;
	}
	return (NULL);
}
