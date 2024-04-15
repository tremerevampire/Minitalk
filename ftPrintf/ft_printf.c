/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:59 by acastejo          #+#    #+#             */
/*   Updated: 2023/11/10 14:53:50 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsbase(unsigned long long n, char *ind, int *i)
{
	int	base;

	if (*i == -1)
		return ;
	base = ft_strlen(ind);
	if (n >= (unsigned int)base)
	{
		ft_putunsbase(n / base, ind, i);
		if (*i == -1)
			return ;
	}
	ft_putchar(ind[n % base], i);
}

void	ft_putunsigned(unsigned long long n, int *i)
{
	if (*i == -1)
		return ;
	if (n >= 10)
	{
		ft_putunsigned (n / 10, i);
		if (*i == -1)
			return ;
	}
	ft_putchar ((n % 10) + 48, i);
}

void	ft_whattype(const char *format, va_list ap, int *i)
{
	format++;
	if (*format == 'c')
		ft_putchar(va_arg (ap, int), i);
	else if (*format == 's')
		ft_putstr (va_arg(ap, char *), i);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int), i);
	else if (*format == 'u')
		ft_putunsigned (va_arg(ap, unsigned int), i);
	else if (*format == 'p')
	{
		ft_putstr ("0x", i);
		if (*i != -1)
			ft_putunsbase(va_arg(ap, unsigned long long),
				"0123456789abcdef", i);
	}
	else if (*format == 'x')
		ft_putunsbase (va_arg(ap, unsigned int), "0123456789abcdef", i);
	else if (*format == 'X')
		ft_putunsbase (va_arg(ap, unsigned int), "0123456789ABCDEF", i);
	else if (*format == '%')
		ft_putchar('%', i);
	else
		ft_putchar(*format, i);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;

	va_start (ap, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_whattype(format, ap, &i);
			if (*format == '\0')
				return (i);
			format++;
		}
		else
			ft_putchar(*format, &i);
		if (i == -1)
			return (i);
		format++;
	}
	va_end (ap);
	return (i);
}
