/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:45:47 by brunmigu          #+#    #+#             */
/*   Updated: 2025/04/12 12:00:59 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	counter;
	size_t	counter_s2;

	counter = 0;
	counter_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	str_join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	while (s1[counter])
	{
		str_join[counter] = s1[counter];
		counter++;
	}
	while (s2[counter_s2])
	{
		str_join[counter + counter_s2] = s2[counter_s2];
		counter_s2++;
	}
	str_join[counter + counter_s2] = 0;
	return (str_join);
}
