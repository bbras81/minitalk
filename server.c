/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:08:28 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/06 16:16:30 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_int(int signal, int len, int bit)
{
	len <<= 1;
	if (signal == SIGUSR1)
		len |= 1;
	bit++;
}
static char	get_char(int signal, int len, int bit)
{
	len <<= 1;
	if (signal == SIGUSR1)
		len |= 1;
	bit++;
	return (bit);
}

static void	handler(int signal, siginfo_t *info, void *more_info)
{
	static int	len;
	static int	bit;

	(void)info;
	(void)more_info;
	get_int(signal, len, bit);
	if (bit == 32)
	{
		ft_printf("%d", len);
		bit = 0;
		len = 0;
	}
}

int	main(void)
{
	ft_printf("Server running and listen...\n");
	ft_printf("Server PID %d\n", getpid());
	my_signal_func(SIGUSR1, handler, true);
	my_signal_func(SIGUSR2, handler, true);
	while (1)
		pause();
}
