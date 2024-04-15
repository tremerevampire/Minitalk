/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:37 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/13 18:59:55 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../inc/minitalk.h"
#include "../ftPrintf/ft_printf.h"

pid_t	ft_atoi(char *num)
{
	long long int	n;
	int				i;
	int				sign;

	n = 0;
	i = 0;
	sign = 1;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign = -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		n = n * 10 + num[i] - '0';
		i++;
	}
	if (n < 0 || n > INT_MAX)
		return (-1);
	return (n * sign);
}

void	ft_encrypt(unsigned char c, pid_t pid)
{
	unsigned char	bit;
	int				octa;

	octa = 7;
	while (octa >= 0)
	{
		if (c >> octa & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Invalid PID\n");
				exit (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Invalid PID\n");
				exit (0);
			}
		}
		octa--;
		usleep(350);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Invalid PID");
			return (1);
		}
		else
		{
			while (*argv[2])
			{
				ft_encrypt(*argv[2], pid);
				argv[2]++;
			}
			ft_encrypt(*argv[2], pid);
			return (0);
		}
	}
	ft_printf("Invalid argument");
	return (1);
}
