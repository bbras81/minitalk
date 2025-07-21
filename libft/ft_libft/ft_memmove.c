/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:34:02 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:28 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Moves memory from source to destination, handling overlap.
 *
 * @param dest Destination buffer.
 * @param src Source buffer.
 * @param n Number of bytes to move.
 * @return void* Pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	if (s >= d)
		return (ft_memcpy(d, s, n));
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
