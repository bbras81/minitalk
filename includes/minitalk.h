/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:46:44 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/21 11:09:25 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

void	my_signal_func(int signal, void *handler, bool use_siginfo);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
#endif
