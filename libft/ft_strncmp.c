/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:59:04 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/03 12:34:42 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char unsigned	*str1;
	char unsigned	*str2;
	size_t			i;
	size_t			dif;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		i++;
	}
	if (i == n)
		i--;
	dif = str1[i] - str2[i];
	return (dif);
}
