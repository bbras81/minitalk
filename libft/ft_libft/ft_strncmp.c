/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:40:51 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:33 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Compares two strings up to n characters.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n Number of characters to compare.
 * @return int The difference between the first differing characters.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		if ((unsigned char)s1[counter] != (unsigned char)s2[counter])
		{
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		}
		if (s1[counter] == '\0')
			return (0);
		counter++;
	}
	return (0);
}
