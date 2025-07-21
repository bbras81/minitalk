/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:06:57 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/13 11:14:00 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

enum
{
	READY,
	BUSY,
};
void	my_signal_func(int signal, void *handler, bool use_siginfo);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
#endif
