/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastejo <acastejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:37:20 by acastejo          #+#    #+#             */
/*   Updated: 2024/05/03 13:04:59 by acastejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../../ftPrintf/ft_printf.h"
# include "../../libft/libft.h"

typedef struct s_bit
{
	char	c;
	size_t	bit;
}	t_bit;	

t_bit	g_msg;

#endif