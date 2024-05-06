/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:01 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/06 14:07:12 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

pid_t	g_clientpid;

void	ft_message(char *msg)
{
	ft_printf("%s\n", msg);
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
			bit = 0;
			str[0] = 0;
			return (i);
		}
		c = 0;
	}
	bit++;
	return (0);
}

void	ft_locatemsg(int signal, int size)
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
			ft_message(msg);
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
	{	
		g_clientpid = info->si_pid;
		size = 0;
		message = false;
	}
	if (!message)
	{
		size = ft_sizemem(signal);
		if (size > 0)
			message = true;
	}
	if (message)
	{
		ft_locatemsg(signal, size);
		size = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: [ %i ] \n", getpid());
	sa.sa_sigaction = decod;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause ();
		usleep(25);
		kill(g_clientpid, SIGUSR2);
	}
	return (0);
}
