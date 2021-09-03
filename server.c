/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:41:19 by hadufer           #+#    #+#             */
/*   Updated: 2021/09/03 16:17:58 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

unsigned char	g_buff[2];

void	sig_handler(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		g_buff[0] |= (0x1 << g_buff[1]);
		g_buff[1]++;
	}
	if (sig_num == SIGUSR2)
		g_buff[1]++;
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	g_buff[0] = 0;
	g_buff[1] = 0;
	while (1)
	{
		if (g_buff[1] == 7)
		{
			ft_putchar_fd(g_buff[0], 1);
			g_buff[0] = 0;
			g_buff[1] = 0;
		}
	}
}
