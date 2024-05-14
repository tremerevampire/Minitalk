/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:37:20 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/14 13:05:45 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../ftPrintf/ft_printf.h"
# include "../../libft/libft.h"

typedef struct s_msg
{
	unsigned char	c;
	size_t			bit;
	int				client_pid;
	size_t			size;
	char			*str;
	int				message;
	size_t			i;
}	t_msg;

#endif