/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:41 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/19 18:26:37 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
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

void	ft_feedback(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sended\n");
}

void	ft_encrypt(unsigned char c, pid_t pid)
{
	unsigned char	bit;
	int				octa;
	static int		flag;

	flag = 0;
	if (!flag)
	{
		signal(SIGUSR1, ft_feedback);
		signal(SIGUSR2, ft_feedback);
		flag = 1;
	}
	octa = 7;
	while (octa >= 0)
	{
		if (c >> octa & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (ft_printf("Invalid pid\n"));
			pause();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit (ft_printf("Invalid pid\n"));
			pause();
		}
		octa--;
		usleep(50);
	//	usleep(200);
		// signal(SIGUSR2, ft_feedback);
		// signal(SIGUSR1, ft_feedback);
		// if (octa!= 0)
		// 	pause();
		// usleep(50);
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
