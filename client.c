/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:08:53 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/13 12:27:06 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server;

void	end_handler(int signo)
{
	write(STDOUT_FILENO, "ok", 2);
	exit(EXIT_SUCCESS);
}

void	ack_handler(int signo)
{
	g_server = READY;
}

void	send_char(char chr, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (chr & (0b10000000 >> bit))
			Kill(server, SIGUSR1);
		else
			Kill(server, SIGUSR2);
		++bit;
	}
	while (g_server == BUSY)
		usleep(42);
	g_server = BUSY;
}

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage = ./client <PID> message");
		exit(EXIT_FAILURE);
	}
	server = ft_atoi(argv[1]);
	message = argv[2];
	Signal(SIGUSR1, ack_handler, false);
	Signal(SIGUSR2, end_handler, false);
	while (*message)
		send_char(*message++, server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}
