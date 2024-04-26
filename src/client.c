/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:37 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/23 13:00:04 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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
