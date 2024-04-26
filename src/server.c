/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:33 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/23 12:59:31 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_message(void)
{
	ft_printf("%s\n", g_msg.str);
	free(g_msg.str);
	g_msg.str = NULL;
}

void	decod(int signum)
{
	char	*aux;

	if (signum == SIGUSR1)
		g_msg.c = g_msg.c << 1 | 1;
	else if (signum == SIGUSR2)
		g_msg.c = g_msg.c << 1;
	if (g_msg.bit == 7)
	{
		if (!g_msg.str)
			aux = ft_calloc(1, 1);
		else
			aux = g_msg.str;
		g_msg.str = ft_strjoin(aux, &g_msg.c);
		free(aux);
		g_msg.bit = -1;
		if (g_msg.c == 0)
			ft_message();
		g_msg.c = 0;
	}
	g_msg.bit++;
}

int	main(void)
{
	pid_t		pid;

	pid = getpid();
	ft_printf("PID: [ %i ] \n", pid);
	signal(SIGUSR1, decod);
	signal(SIGUSR2, decod);
	while (1)
		pause ();
	return (0);
}
