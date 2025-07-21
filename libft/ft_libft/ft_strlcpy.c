/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:12:21 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:19 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Copies up to dsize - 1 characters from src to dst,
 * @brief null-terminating the result.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param dsize The size of the destination buffer.
 * @return size_t Total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	counter;

	counter = 0;
	if (dsize == 0)
	{
		return (ft_strlen((char *)src));
	}
	while (src[counter] && counter < dsize - 1)
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (ft_strlen((char *)src));
}
