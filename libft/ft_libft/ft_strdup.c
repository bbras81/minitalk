/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:39:52 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:03 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Duplicates a string.
 *
 * @param s1 The string to duplicate.
 * @return char* The newly allocated copy of the string.
 */
char	*ft_strdup(const char *s1)
{
	char	*newstr;
	size_t	counter;

	if (!s1)
		return (NULL);
	counter = 0;
	newstr = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	while (s1[counter])
	{
		newstr[counter] = s1[counter];
		counter++;
	}
	newstr[counter] = '\0';
	return (newstr);
}
