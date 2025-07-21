/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:17 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:57 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Converts a character to uppercase.
 *
 * @param chr The character to convert.
 * @return int The uppercase equivalent if applicable.
 */
int	ft_toupper(int chr)
{
	if (chr >= 97 && chr <= 122)
	{
		chr -= 32;
	}
	return (chr);
}
