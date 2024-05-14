/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:33 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/11 13:02:59 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static bool	message;

void	ft_message(char *msg)
{
	ft_printf("%s\n", msg);
	message = false;
}

int	ft_sizemem(int signal)
{
	static unsigned int	bit;
	static char			c;
	static char			str[7];
	static int			i;

	if (signal == SIGUSR1)
		c = c << 1 | 1;
	else if (signal == SIGUSR2)
		c = c << 1;
	if (bit++ == 7)
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
	// bit++;
	return (0);
}

void	ft_locatemsg(int signal, int size)
{
	static char				*msg;
	static unsigned int		i;
	static unsigned char	letter;
	static int				pos;

	if (!msg)
		msg = (char *)ft_calloc(size + 1, sizeof(char));
	if (signal == SIGUSR1)
		letter = letter << 1 | 1;
	else if (signal == SIGUSR2)
		letter = letter << 1;
	if (pos == 7)
	{
		msg[i++] = letter;
		pos = -1;
		if (letter == 0)
		{
			ft_message(msg);
			free(msg);
			msg = NULL;
			i = 0;
		}
		letter = 0;
	}
	pos++;
}

void	decod(int signal)
{
	static int			size;

	if (!message)
	{
		size = ft_sizemem(signal);
		if (size > 0)
			message = true;
	}
	else if (message)
	{
		ft_locatemsg(signal, size);
		size = 0;
	}
}

int	main(void)
{
	ft_printf("PID: [ %i ] \n", getpid());
	signal(SIGUSR1, decod);
	signal(SIGUSR2, decod);
	while (1)
	{
		pause ();
	}
	return (0);
}
