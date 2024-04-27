/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:01 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/27 17:36:13 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

pid_t	g_clientpid;

void	ft_message(char *msg, bool **message)
{
	ft_printf("%s\n", msg);
	message = false;
	kill(g_clientpid, SIGUSR1);
}

int	ft_sizemem(int signal)
{
	static int	bit;
	static char	c;
	static char	*aux;
	static char	str[7];
	static int	i;

	if (signal == SIGUSR1)
		c = c << 1 | 1;
	else if (signal == SIGUSR2)
		c = c << 1;
	if (bit == 7)
	{
		if (!str[0])
			i = 0;
		str[i++] = c;
		bit = -1;
		if (c == 0)
		{
			i = ft_atoi(str);
			return (i);
		}
		c = 0;
	}
	bit++;
	return (0);
}

void	ft_locatemsg(int signal, int size, bool *message)
{
	static char				*msg;
	static unsigned int		i;
	static unsigned char	letter;
	static int				pos;

	if (!msg)
	{
		msg = (char *)ft_calloc(size + 1, sizeof(char));
		i = 0;
		pos = -1;
	}
	if (signal == SIGUSR1)
		letter = letter << 1 | 1;
	else if (signal == SIGUSR2)
		letter = letter << 1;
	if (pos == 7)
	{
		msg[i] = letter;
		i++;
		pos = -1;
		if (letter == 0)
		{
			ft_message(msg, &message);
			free(msg);
			msg = NULL;
		}
		letter = 0;
	}
	pos++;
}

void	decod(int signal, siginfo_t *info, void *context)
{
	static bool	message;
	int			size;

	(void)context;
	if (g_clientpid != info->si_pid)
		g_clientpid = info->si_pid;
	if (!message)
	{
		size = ft_sizemem(signal);
		if (size > 0)
			message = true;
	}
	if (message)
		ft_locatemsg(signal, size, &message);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: [ %i ] \n", getpid());
	sa.sa_sigaction = decod;
	sa.sa_mask = 0;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause ();
		usleep(5);
		kill(g_clientpid, SIGUSR2);
	}
	return (0);
}
