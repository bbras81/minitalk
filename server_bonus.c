/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:31:57 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/12 22:32:25 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;

	(void)context;
	current_char <<= 1;
	if (signum == SIGUSR2)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bit_index = 0;
		if (info && info->si_pid != 0)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	signal_rec;

	ft_printf("Welcome to brunmigu's Server :-)\n");
	ft_printf("Server PID: %d\n", getpid());
	signal_rec.sa_sigaction = handler_signal;
	signal_rec.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_rec.sa_mask);
	sigaction(SIGUSR1, &signal_rec, NULL);
	sigaction(SIGUSR2, &signal_rec, NULL);
	while (1)
		pause();
	return (0);
}
