/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:28:54 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:18:45 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Checks if a character is alphanumeric.
 *
 * @param chr The character to check.
 * @return int Non-zero if alphanumeric, zero otherwise.
 */

int	ft_isalnum(int chr)
{
	if ((chr >= '0' && chr <= '9') || (chr >= 'A' && chr <= 'Z') || (chr >= 'a'
			&& chr <= 'z'))
		return (1);
	return (0);
}
