/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:31:36 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/15 17:28:27 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srce;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dest = (char *) dst;
	srce = (char *) src;
	if ((size_t *)dst >= (size_t *)src && dst && src)
	{
		while (n--)
		{
			dest[n] = srce[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = srce[i];
			i++;
		}
	}
	return (dst);
}
