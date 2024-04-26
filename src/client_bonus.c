/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:41 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/26 20:07:52 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_feedback(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sended\n");
}

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
		pause();
		usleep(100);
	}
}

void	ft_sendlen(int len, pid_t pid)
{
	char	*str;

	str = ft_itoa(len);
	while (*str)
	{
		ft_encrypt(*str, pid);
		str++;
	}
	ft_encrypt(0, pid);
	pause();
	usleep(5);
}

void	ft_sendmsg(char const *str, pid_t pid)
{
	while (*str)
	{
		ft_encrypt(*str, pid);
		str++;
	}
	ft_encrypt(0, pid);
	pause();
	usleep (5);
}

int	main(int argc, char **argv)
{
	int	len;

	signal(SIGUSR1, ft_feedback);
	signal(SIGUSR2, ft_feedback);
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0)
			return (ft_printf("Invalid PID"), 1);
		else
		{
			len = ft_strlen(argv[2]);
			ft_sendlen(len, ft_atoi(argv[1]));
			usleep(20);
			ft_printf("caracteres enviados: %i\n", len);
			ft_sendmsg(argv[2], ft_atoi(argv[1]));
			ft_printf("Characters sended: %i\n", len);
			pause ();
			return (0);
		}
	}
	ft_printf("Invalid argument");
	return (1);
}
