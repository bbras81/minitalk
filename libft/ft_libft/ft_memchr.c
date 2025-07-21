/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:55:06 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:16 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Searches for a character in a memory area.
 *
 * @param s The memory area.
 * @param c The character to search for.
 * @param n Number of bytes to search.
 * @return void* Pointer to the matching byte or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		if (str[counter] == chr)
			return ((void *)&str[counter]);
		counter++;
	}
	return (NULL);
}
