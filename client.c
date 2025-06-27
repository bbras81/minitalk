/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:49:06 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/27 09:50:01 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char chr, pid_t server)
{
	int	bit;

	bit = -1;
	while (++bit < CHAR_BIT)
	{
		if (((unsigned char)(chr >> (7 - bit)) & 1) == 1)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		usleep(100);
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
