/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:32:18 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/12 22:32:47 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	got_ack = 0;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		got_ack = 1;
}

// Função para enviar um caractere e esperar confirmação do servidor
void	send_char(int pid, unsigned char c, sigset_t *mask)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> (7 - i)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100); // Pode ajustar, mas 100µs costuma ser estável
	}
	// Espera o sinal SIGUSR1 com sigsuspend
	while (!got_ack)
		sigsuspend(mask); // Espera com máscara de sinais desbloqueada
	got_ack = 0;
}

void	sending_signals(int pid, char *message, sigset_t *mask)
{
	int	i;

	i = 0;
	while (message[i])
		send_char(pid, (unsigned char)message[i++], mask);
	send_char(pid, '\0', mask); // Envia byte nulo para sinalizar fim
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*message;
	struct sigaction	sa;

	sigset_t mask, oldmask;
	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	message = argv[2];
	// Configura o handler do sinal
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	// Bloqueia SIGUSR1 temporariamente para preparar o sigsuspend
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigprocmask(SIG_BLOCK, &mask, &oldmask);
	sending_signals(server_pid, message, &oldmask);
	printf("Message sent to PID %d\n", server_pid);
	return (0);
}
