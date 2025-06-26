/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:49:36 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/26 13:39:52 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *more_info)
{
	static char	chr;
	static int	bit;

	// static pid_t	client;
	(void)more_info;
	if (signal == SIGUSR1)
		chr |= (0b10000000 >> bit);
	++bit;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (chr == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			return ;
		}
		write(STDOUT_FILENO, &chr, 1);
	}
}

int	main(void)
{
	ft_printf("Server running and listen...\n");
	ft_printf("Server PID %d\n", getpid());
	my_signal_func(SIGUSR1, handler, true);
	my_signal_func(SIGUSR2, handler, true);
	while (1)
	{
		pause();
	}
}
