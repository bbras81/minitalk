/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:25:29 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:18:49 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Checks if a character is alphabetic.
 *
 * @param chr The character to check.
 * @return int Non-zero if alphabetic, zero otherwise.
 */
int	ft_isalpha(int chr)
{
	if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z'))
		return (1);
	return (0);
}
