/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:28:22 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/15 17:29:13 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	srclen;
	size_t	aux;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen < dstsize)
		aux = srclen + dstlen;
	else
		aux = srclen + dstsize;
	while (src[i] != '\0' && (i + dstlen) < (dstsize - 1) && dstsize != 0)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[i + dstlen] = 0;
	return (aux);
}
