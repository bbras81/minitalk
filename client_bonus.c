/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:06:28 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/27 10:06:37 by brunmigu         ###   ########.fr       */
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
