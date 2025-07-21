/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:34:03 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:43 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Trims characters from the beginning and end of a string.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to trim.
 * @return char* The trimmed string.
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	counter_start;
	size_t	counter_end;

	counter_start = 0;
	if (!s1 || !set || s1[0] == '\0')
		return (ft_strdup(""));
	counter_end = ft_strlen(s1) - 1;
	while (s1[counter_start] && ft_strchr(set, s1[counter_start]))
		counter_start++;
	while (counter_end > counter_start && ft_strchr(set, s1[counter_end]))
		counter_end--;
	return (ft_substr(s1, counter_start, counter_end - counter_start + 1));
}
