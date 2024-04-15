/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:06:13 by acastejo          #+#    #+#             */
/*   Updated: 2023/11/10 14:53:16 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(char const *format, ...);
void	ft_putstr(char *s, int *i);
void	ft_putchar(char c, int *i);
void	ft_putnbr(int n, int *i);
int		ft_strlen(const char *s);

#endif
