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
	}
	++bit;
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
	while (*message)
	{
		send_char(*message++, server);
	}
	send_char('\0', server);
	return (EXIT_SUCCESS);
}
