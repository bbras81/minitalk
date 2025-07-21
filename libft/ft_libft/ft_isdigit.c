/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:58:48 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:19:03 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Checks if a character is a digit.
 *
 * @param c The character to check.
 * @return int Non-zero if digit, zero otherwise.
 */
int	ft_isdigit(int chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	return (0);
}
