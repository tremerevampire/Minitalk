/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:01 by acastejo          #+#    #+#             */
/*   Updated: 2024/04/26 20:32:45 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	g_size = 0;

void	ft_message(pid_t pid)
{
	ft_printf("devolución de la señal\n");
	usleep(50);
	kill(pid, SIGUSR1);
	g_size = 0;
}

void	ft_sizemem(int signal, pid_t pid)
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
			g_size = ft_atoi(str);
		c = 0;
	}
	bit++;
	kill(pid, SIGUSR2);
}

void	ft_locatemsg(int signal, pid_t pid)
{
	static char				*msg;
	static int				i;
	static unsigned char	letter;
	static int				pos;

	if (!msg)
	{
		msg = (char *)ft_calloc(g_size + 1, sizeof(char));
		i = 0;
		letter = 0;
		pos = 0;
	}
	if (signal == SIGUSR1)
		letter = letter << 1 | 1;
	else if (signal == SIGUSR2)
		letter = letter << 1;
	if (pos == 7)
	{
		ft_printf("%i\n", letter);
		msg[i] = letter;
		i++;
		pos = -1;
		if (letter == 0)
		{
			write(1, msg, g_size);
			write(1, "\n", 1);
			ft_message(pid);
		}
		letter = 0;
	}
	ft_printf("|%c|\n", letter);
	pos++;
	usleep(5);
	kill(pid, SIGUSR2);
}

void	decod(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (g_size == 0)
		ft_sizemem(signal, info->si_pid);
	if (g_size != 0)
	{
		ft_printf("El tamaño del string va a ser: %i\n", g_size);
		ft_locatemsg(signal, info->si_pid);
	}
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
		pause ();
	return (0);
}
