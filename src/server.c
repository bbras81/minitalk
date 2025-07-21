/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:08:28 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/13 10:37:46 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>


static void	handler(int signal)
{
	static char	len;
	static int	bit;
	static char	*message = NULL;
	char		temp[2];

	len <<= 1;
	if (signal == SIGUSR1)
		len |= 1;
	bit++;
	if (bit == 8)
	{
		temp[0] = len;
		temp[1] = '\0';
		if (!message)
			message = ft_strdup("");
		char *old = message;
		message = ft_strjoin(message, temp);
		free(old);
		bit = 0;
		len = 0;
	}
	if (len == 0)
	{
		ft_putstr_fd(message, STDOUT_FILENO);
		free(message);
		message = NULL;
	}
}

int	main(void)
{
	ft_printf("Server running and listen...\n");
	ft_printf("Server PID %d\n", getpid());
	my_signal_func(SIGUSR1, handler, false);
	my_signal_func(SIGUSR2, handler, false);
	while (1)
		pause();
}
