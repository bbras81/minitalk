/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:35:09 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:52 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Converts a character to lowercase.
 *
 * @param chr The character to convert.
 * @return int The lowercase equivalent if applicable.
 */
int	ft_tolower(int chr)
{
	if (chr >= 65 && chr <= 90)
	{
		chr += 32;
	}
	return (chr);
}
