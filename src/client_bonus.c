/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:41 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/14 14:43:58 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_feedback(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		ft_printf("Message sended\n");
}

void	ft_encrypt(unsigned char c, pid_t pid)
{
	unsigned short	octa;

	octa = 8;
	while (octa--)
	{
		if (c >> octa & 0x01)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (ft_printf("Invalid pid\n"));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit (ft_printf("Invalid pid\n"));
		}
		pause();
		usleep(5);
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
		pause ();
	}
}

void	ft_sendmsg(char const *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_encrypt(str[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					len;
	struct sigaction	sa;

	sa.sa_sigaction = ft_feedback;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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
