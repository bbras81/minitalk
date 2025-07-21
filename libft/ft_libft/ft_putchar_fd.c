/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:36:40 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:35 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Outputs a character to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
