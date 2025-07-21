/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:06:28 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/29 12:15:07 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_state = BUSY;

static void	ack_handler(int sig)
{
	(void)sig;
	g_state = READY;
}

static void	end_handler(int sig)
{
	(void)sig;
	ft_printf("\n✅ Mensagem recebida pelo servidor!\n");
	exit(EXIT_SUCCESS);
}

static void	send_char(char chr, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if ((chr & (0x80 >> bit)) != 0)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		bit++;
		while (g_state == BUSY)
			pause();
		g_state = BUSY;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage = .client <PID> message");
		exit(EXIT_FAILURE);
	}
	server = ft_atoi(argv[1]);
	message = argv[2];
	my_signal_func(SIGUSR1, ack_handler, false);
	my_signal_func(SIGUSR2, end_handler, false);
	i = 0;
	while (message[i])
		send_char(message[i++], server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}
