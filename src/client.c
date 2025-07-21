/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:45:37 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/21 12:17:31 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile sig_atomic_t	ack = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	ack = 1;
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i = 7;

	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
	while (!ack)
		pause();
	ack = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;
	char				*str;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (*str)
		send_char(pid, *str++);
send_char(pid, '\0');
return (0);
}
