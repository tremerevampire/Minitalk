/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:01 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/19 18:27:54 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include "../ftPrintf/ft_printf.h"

void	decod(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		g_msg.c = g_msg.c << 1 | 1;
		kill(info->si_pid, SIGUSR2);
	}
	else if (signal == SIGUSR2)
	{
		g_msg.c = g_msg.c << 1;
		kill(info->si_pid, SIGUSR2);
	}
	if (g_msg.bit == 7)
	{
		ft_printf("%c", g_msg.c);
		g_msg.bit = -1;
		if (g_msg.c == 0)
			kill(info->si_pid, SIGUSR1);
		g_msg.c = 0;
	}
	g_msg.bit++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: [ %i ] \n", pid);
	sa.sa_sigaction = decod;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
