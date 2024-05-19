/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:06:13 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/07 16:48:12 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

int		ft_printf(char const *format, ...);
void	ft_putstr(char *s, int *i);
void	ft_putchar(char c, int *i);
void	ft_putnbr(int n, int *i);
int		ft_strlenprint(const char *s);

#endif
