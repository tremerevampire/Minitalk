/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:01 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/13 19:00:29 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void decod(int signum)
{
	if (signum == SIGUSR1)
		g_msg.c = g_msg.c << 1 | 1;
	else if (signum == SIGUSR2)
		g_msg.c = g_msg.c << 1;
	if (g_msg.bit == 7)
	{
		ft_printf("%c", g_msg.c);
		g_msg.c = 0;
		g_msg.bit = -1;
	}
	g_msg.bit++;
}

int	main(void)
{
	pid_t		pid;

	pid = getpid();
	ft_printf("PID: [ %i ] \n", pid);
	//sigaction(SIGUSR1)
	signal(SIGUSR1, decod);
	signal(SIGUSR2, decod);
	while (1)
		pause ();
	return (0);
}
