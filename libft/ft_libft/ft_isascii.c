/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:40:53 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:18:53 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Checks if a character is an ASCII character.
 *
 * @param chr The character to check.
 * @return int Non-zero if ASCII, zero otherwise.
 */

int	ft_isascii(int chr)
{
	if (chr >= 0 && chr < 128)
		return (1);
	return (0);
}
