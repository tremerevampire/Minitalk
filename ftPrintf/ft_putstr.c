/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:03:49 by acastejo          #+#    #+#             */
/*   Updated: 2023/11/10 14:52:24 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *i)
{
	if (!s)
	{
		ft_putstr ("(null)", i);
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, i);
		if (*i == -1)
			return ;
		s++;
	}
}
