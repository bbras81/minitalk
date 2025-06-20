/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:48:52 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/16 10:22:02 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		chr;
	static int		bit;
	static pid_t	client;

	client = info->si_pid;
	(void)more_info;
	if (signo == SIGUSR1)
		chr |= (0b10000000 >> bit);
	else if (signo == SIGUSR2)
		chr |= ~(0b10000000);
	++bit;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (chr == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			Kill(client, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &chr, 1);
	}
	kill(client, SIGUSR1);
}

int	main(void)
{
	ft_printf("Server Running and listen...\n");
	ft_printf("Server PID %d\n", getpid());
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
