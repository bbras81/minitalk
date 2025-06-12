/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:42:06 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/10 11:50:25 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_signal(int signum)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;

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
}

int	main(void)
{
	struct sigaction	signal_rec;

	ft_printf("Welcome to brunmigu's Server :-)\n");
	ft_printf("Server PID: %d\n", getpid());
	signal_rec.sa_handler = handler_signal;
	signal_rec.sa_flags = SA_RESTART;
	sigemptyset(&signal_rec.sa_mask);
	sigaction(SIGUSR1, &signal_rec, NULL);
	sigaction(SIGUSR2, &signal_rec, NULL);
	while (1)
		pause();
	return (0);
}
