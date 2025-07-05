/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:56:25 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/05 12:45:17 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

static void	handler(int signal, siginfo_t *info, void *more_info)
{
	static int	len = 0;
	static int	bit = 0;
	static char	*message;

	(void)info;
	(void)more_info;
	len <<= 1;
	if (signal == SIGUSR1)
		len |= 1;
	bit++;
	if (bit == 32)
	{
		ft_printf("%d", len);
		bit = 0;
		len = 0;
	}
	if (bit == 8)
	{
    
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
