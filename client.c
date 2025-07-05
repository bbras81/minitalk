/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:56:19 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/05 12:43:24 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int nbr, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((unsigned int)nbr >> (7 - bit)) & 1)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		bit++;
		usleep(100);
	}
}

static void	send_int(int nbr, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if (((unsigned int)nbr >> (31 - bit)) & 1)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server;
	int		len;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <int>\n");
		return (1);
	}
	server = ft_atoi(argv[1]);
	message = argv[2];
	len = ft_strlen(message);
	send_int(len, server);
	len = 0;
	//	while (*message)
	//	send_char(*message++, server);
	//\send_char('\0', server);
	return (0);
}
