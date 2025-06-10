/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:08:26 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/06 13:14:46 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sending_signals(int pid, char *message)
{
	int	i;
	int	letter;

	letter = 0;
	while (message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		letter++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("[ERROR] bad argument!");
			return (0);
		}
		message = argv[2];
		if (message[0] == 0)
		{
			ft_printf("[ERROR] Bad string");
			return (0);
		}
		sending_signals(server_pid, message);
	}
	ft_printf("User Pid: %d", server_pid);
	return (0);
}
