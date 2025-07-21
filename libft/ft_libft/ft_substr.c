/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:05:32 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:48 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Extracts a substring from a string.
 *
 * @param s The source string.
 * @param start The starting index.
 * @param len The length of the substring.
 * @return char* The extracted substring.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counter;
	char	*substr;

	counter = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (counter < len)
	{
		substr[counter] = s[start];
		counter++;
		start++;
	}
	substr[counter] = '\0';
	return (substr);
}
