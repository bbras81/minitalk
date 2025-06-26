/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:42:17 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/26 15:28:17 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void my_signal_func(int signal, void *handler, bool use_siginfo)
{
	struct sigaction sa;

	if (use_siginfo)
	{
		sa.sa_flags =
	}
}
