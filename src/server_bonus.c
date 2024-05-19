/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:01 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/18 17:24:05 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_msg	g_msg;

void	ft_message(void)
{
	write(1, g_msg.str, g_msg.size);
	kill(g_msg.client_pid, SIGUSR1);
	g_msg.bit = 0;
	g_msg.c = 0;
	g_msg.i = 0;
	free(g_msg.str);
	g_msg.str = NULL;
	g_msg.message = 0;
	g_msg.size = 0;
}

void	ft_sizemem(int signal)
{
	if (signal == SIGUSR1)
		g_msg.size = g_msg.size << 1 | 1;
	else if (signal == SIGUSR2)
		g_msg.size = g_msg.size << 1;
	g_msg.bit++;
	if (g_msg.bit == 32)
	{
		g_msg.bit = 0;
		g_msg.message = 1;
	}
}

void	ft_locatemsg(int signal)
{
	static int	j;

	if (!g_msg.str)
	{
		j = 0;
		g_msg.str = (char *)ft_calloc(g_msg.size + 1, sizeof(char));
	}
	if (signal == SIGUSR1)
		g_msg.c = g_msg.c << 1 | 0x01;
	else if (signal == SIGUSR2)
		g_msg.c = g_msg.c << 1;
	if (g_msg.bit++ == 7)
	{
		ft_printf("%i\n", j++);
		g_msg.str[g_msg.i] = g_msg.c;
		g_msg.bit = 0;
		g_msg.c = 0;
		g_msg.i++;
		if (g_msg.i == g_msg.size)
			ft_message();
	}
}

void	ft_decod(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (g_msg.client_pid != info->si_pid)
	{
		g_msg.client_pid = info->si_pid;
		g_msg.size = 0;
		g_msg.message = 0;
	}
	if (!g_msg.message)
		ft_sizemem(signal);
	else if (g_msg.message)
		ft_locatemsg(signal);
	usleep(10);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: [ %i ] \n", getpid());
	sa.sa_sigaction = ft_decod;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause ();
		//usleep(700);
		kill(g_msg.client_pid, SIGUSR2);
	}
	return (0);
}
