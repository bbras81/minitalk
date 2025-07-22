/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:22:41 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/21 12:42:46 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/includes/libft.h"
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
size_t	ft_strlen(const char *str);
#endif
