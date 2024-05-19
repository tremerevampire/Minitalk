/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:33:20 by acastejo          #+#    #+#             */
/*   Updated: 2023/11/15 19:04:36 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ncount(int n)
{
	size_t	i;

	i = 0;
	if (n < -2147483647)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	const char	*digits;
	long		t;

	t = n;
	digits = "0123456789";
	i = ft_ncount(t);
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (NULL);
	if (t == 0)
		str[0] = '0';
	if (t < 0)
	{
		str[0] = '-';
		t = -t;
	}
	while (t)
	{
		str[--i] = digits[t % 10];
		t = t / 10;
	}
	return (str);
}
