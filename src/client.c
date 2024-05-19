/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:37 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/17 18:53:56 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_encrypt(unsigned char c, pid_t pid)
{
	int				octa;

	octa = 7;
	while (octa >= 0)
	{
		if (c >> octa & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (ft_printf("Invalid pid\n"));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit (ft_printf("Invalid pid\n"));
		}
		octa--;
		usleep(500);
	}
}

void	ft_sendlen(size_t len, pid_t pid)
{
	unsigned short	bit;

	bit = 32;
	while (bit != 0)
	{
		bit--;
		if (len >> bit & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (ft_printf("Invalid pid\n"));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit (ft_printf("Invalid pid\n"));
		}
		usleep(300);
	}
}

void	ft_sendmsg(char const *str, pid_t pid)
{
	while (*str)
	{
		ft_encrypt(*str, pid);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0)
			return (ft_printf("Invalid PID"), 1);
		else
		{
			len = ft_strlen(argv[2]);
			ft_sendlen(len, ft_atoi(argv[1]));
			ft_sendmsg(argv[2], ft_atoi(argv[1]));
			return (0);
		}
	}
	ft_printf("Invalid argument");
	return (1);
}
