/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:11:46 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/13 12:31:01 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	found_new_line(char *remainder)
{
	int	counter;

	counter = 0;
	if (!remainder)
		return (0);
	while (remainder[counter])
	{
		if (remainder[counter] == '\n')
			return (1);
		counter++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*extract_line(char *remainder)
{
	char	*new_line;
	int		counter_1;
	int		counter_2;

	if (!remainder || remainder[0] == '\0')
		return (NULL);
	counter_1 = 0;
	while (remainder[counter_1] && remainder[counter_1] != '\n')
		counter_1++;
	if (remainder[counter_1] == '\n')
		counter_1++;
	new_line = malloc(sizeof(char) * counter_1 + 1);
	if (!new_line)
		return (NULL);
	counter_2 = 0;
	while (counter_2 < counter_1)
	{
		new_line[counter_2] = remainder[counter_2];
		counter_2++;
	}
	new_line[counter_2] = '\0';
	return (new_line);
}

char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	int		counter_1;
	int		counter_2;

	if (!remainder)
		return (NULL);
	counter_1 = 0;
	while (remainder[counter_1] && remainder[counter_1] != '\n')
		counter_1++;
	if (remainder[counter_1] == '\n')
		counter_1++;
	if (remainder[counter_1] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc((ft_strlen(remainder) - counter_1) + 1);
	counter_2 = 0;
	while (remainder[counter_1])
		new_remainder[counter_2++] = remainder[counter_1++];
	new_remainder[counter_2] = '\0';
	free(remainder);
	return (new_remainder);
}
