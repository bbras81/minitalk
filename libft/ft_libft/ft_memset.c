/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:10:52 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:32 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Fills a block of memory with a specific byte.
 *
 * @param s The memory area to fill.
 * @param c The byte to fill with.
 * @param n Number of bytes to fill.
 * @return void* Pointer to the memory area b.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			counter;

	ptr = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		ptr[counter] = (unsigned char)c;
		counter++;
	}
	return (ptr);
}
