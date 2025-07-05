/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:13:23 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/26 13:44:36 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
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
void	*ft_calloc(size_t count, size_t size);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
#endif
