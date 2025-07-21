/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:26:13 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:18:39 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Allocates memory based on the count and size and fills it with null's.
 *
 * @param count Number of elements.
 * @param size Size of each element.
 * @return void* Pointer to the allocated memory.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}
