/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:07:18 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/29 12:27:11 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal, siginfo_t *info, void *more_info)
{
	static char		chr = 0;
	static int		bit = 0;
	static pid_t	client = 0;

	(void)more_info;
	if (info->si_pid)
		client = info->si_pid;
	chr <<= 1;
	if (signal == SIGUSR1)
		chr |= 1;
	bit++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (chr == '\0')
		{
			write(1, "\n", 1);
			kill(client, SIGUSR2);
			chr = 0;
			return ;
		}
		write(1, &chr, 1);
		chr = 0;
	}
	kill(client, SIGUSR1);
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
