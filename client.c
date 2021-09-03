/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:48:55 by hadufer           #+#    #+#             */
/*   Updated: 2021/09/03 16:22:20 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

static int	is_pid_valid_display(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
		{
			ft_putstr_fd("Invalid PID\n", 2);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i[2];
	int	pid;
	int	lenght;

	if (argc != 3)
		return (1);
	i[0] = 0;
	if (!is_pid_valid_display(argv[1]))
		return (1);
	pid = ft_atoi(argv[1]);
	lenght = ft_strlen(argv[2]);
	while (lenght-- > 0)
	{
		i[1] = 0;
		while (i[1] < 7)
		{
			if ((argv[2][i[0]]) & (0x1 << i[1]))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(45);
			i[1]++;
		}
		i[0]++;
	}
}
