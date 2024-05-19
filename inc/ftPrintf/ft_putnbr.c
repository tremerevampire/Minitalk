/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:02:45 by acastejo          #+#    #+#             */
/*   Updated: 2023/11/10 14:52:27 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *i)
{
	unsigned int	nbr;

	if (*i == -1)
		return ;
	if (n == -2147483648)
	{
		ft_putstr ("-2147483648", i);
		return ;
	}
	if (n < 0)
	{
		ft_putchar ('-', i);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int) n;
	if (nbr >= 10)
	{
		ft_putnbr (nbr / 10, i);
		if (*i == -1)
			return ;
	}
	ft_putchar ((nbr % 10) + 48, i);
}
