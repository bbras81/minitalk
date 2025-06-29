/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:07:38 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/27 10:07:48 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	my_signal_func(int signal, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (use_siginfo)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
	{
		sa.sa_handler = (void (*)(int))handler;
		sa.sa_flags = 0;
	}
	if (sigaction(signal, &sa, NULL) < 0)
	{
		perror("Sigaction Feild");
		exit(EXIT_FAILURE);
	}
}
