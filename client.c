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

void	sending_signals(int pid, char message)
{
	int	i;

	while (++i < 8)
	{
		if (((unsigned char)(message >> (7 - i)) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}
i = 0;
while (i++ < 8)
{
	kill(pid, SIGUSR1);
	usleep(200);
}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	message = argv[2];
	if (message[0] == '\0')
		return (1);
	while (*message)
		sending_signals(server_pid, *message++);
	ft_printf("Message sent to PID %d\n", server_pid);
	return (EXIT_SUCCESS);
}
