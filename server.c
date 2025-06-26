/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:15:59 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/26 10:22:09 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;
	static pid_t			client_pid;

	client_pid = info->si_pid;
	(void)ucontext;
	current_char <<= 1;
	if (signum == SIGUSR2)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bit_index = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
