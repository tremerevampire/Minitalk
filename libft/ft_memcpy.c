/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:49:01 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/17 17:56:48 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	char const	*srce;
	size_t		i;

	if (!dst && !src && n > 0)
		return (NULL);
	i = 0;
	dest = (char *) dst;
	srce = (const char *) src;
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}
