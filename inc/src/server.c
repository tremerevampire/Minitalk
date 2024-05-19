/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:33 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/17 18:52:53 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_msg	g_msg;

void	ft_message(void)
{
	write(1, g_msg.str, g_msg.size);
	g_msg.bit = 0;
	g_msg.c = 0;
	g_msg.i = 0;
	g_msg.size = 0;
	free(g_msg.str);
	g_msg.str = NULL;
	g_msg.message = 0;
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
	if (!g_msg.str)
		g_msg.str = (char *)ft_calloc(g_msg.size, sizeof(char));
	if (signal == SIGUSR1)
		g_msg.c = g_msg.c << 1 | 0x01;
	else if (signal == SIGUSR2)
		g_msg.c = g_msg.c << 1;
	if (g_msg.bit++ == 7)
	{
		g_msg.str[g_msg.i] = g_msg.c;
		g_msg.bit = 0;
		g_msg.c = 0;
		g_msg.i++;
		if (g_msg.i == g_msg.size)
			ft_message();
	}
}

void	ft_decod(int signal)
{
	if (!g_msg.message)
		ft_sizemem(signal);
	else if (g_msg.message)
		ft_locatemsg(signal);
}

int	main(void)
{
	ft_printf("PID: [ %i ] \n", getpid());
	signal(SIGUSR1, ft_decod);
	signal(SIGUSR2, ft_decod);
	while (1)
	{
		pause ();
	}
	return (0);
}
