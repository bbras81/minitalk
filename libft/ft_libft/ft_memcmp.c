/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:23:53 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:22 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Compares two memory areas byte by byte.
 *
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n Number of bytes to compare.
 * @return int Zero if equal, otherwise the difference between
 * @return first differing bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*str1;
	unsigned char	*str2;

	counter = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (str1[counter] != str2[counter])
			return (str1[counter] - str2[counter]);
		counter++;
	}
	return (0);
}
