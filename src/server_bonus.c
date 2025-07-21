/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:33:17 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:29 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	append_char(char c)
{
	static char	*msg = NULL;
	char		*tmp;
	char		ch[2];

	ch[0] = c;
	ch[1] = '\0';
	if (msg)
	{
		tmp = msg;
		msg = ft_strjoin(msg, ch);
		free(tmp);
	}
	else
		msg = ft_strdup(ch);
	if (c == '\0')
	{
		ft_putstr_fd(msg, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		free(msg);
		msg = NULL;
	}
}

static void	handler(int signal, siginfo_t *info, void *context)
{
    static int				bit = 0;
    static unsigned char	c = 0;

    (void)context;
    c <<= 1;
    if (signal == SIGUSR1)
        c |= 1;
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
        {
            append_char(c);
            kill(info->si_pid, SIGUSR2);
        }
        else
        {
            append_char(c);
            kill(info->si_pid, SIGUSR1);
        }
        bit = 0;
        c = 0;
    }
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server running and listening...\n");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
