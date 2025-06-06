/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:54:18 by brunmigu          #+#    #+#             */
/*   Updated: 2025/04/10 16:18:47 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>

int	main(void)
{
	char *str = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_strnstr(str, "lorem",15));
}*/
