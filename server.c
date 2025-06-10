/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:42:06 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/10 11:51:04 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_printf("Welcome to brunmigu's Server :-)\n");
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		usleep(50);
	return (0);
}
