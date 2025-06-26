/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:49:06 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/26 13:24:55 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void	send_char(char chr, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (chr & (0b10000000 >> bit))
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		usleep(100);
		++bit;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage = .client <PID> message");
		exit(EXIT_FAILURE);
	}
	server = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
		send_char(*message++, server);
	send_char('\0', server);
}
