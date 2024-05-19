/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:02:45 by acastejo          #+#    #+#             */
/*   Updated: 2023/10/12 20:10:14 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int) n;
	if (nbr >= 10)
		ft_putnbr_fd (nbr / 10, fd);
	ft_putchar_fd (nbr % 10 + 48, fd);
}
