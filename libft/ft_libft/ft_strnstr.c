/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:54:18 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:36 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Locates a substring in a string, within the first len characters.
 *
 * @param haystack The string to search in.
 * @param needle The substring to find.
 * @param len Maximum number of characters to search.
 * @return char* Pointer to the beginning of the located substring,
 * @return or NULL if not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter_e;
	size_t	counter_g;

	counter_g = 0;
	counter_e = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[counter_g] && counter_g < len)
	{
		while (haystack[counter_g + counter_e] == needle[counter_e]
			&& haystack[counter_g + counter_e] && counter_g + counter_e < len)
		{
			counter_e++;
			if (needle[counter_e] == 0)
				return ((char *)haystack + counter_g);
		}
		counter_g++;
		counter_e = 0;
	}
	return (NULL);
}
