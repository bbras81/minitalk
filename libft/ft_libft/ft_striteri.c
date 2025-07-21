/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:26:30 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:21:07 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Applies a function to each character of a string (by reference).
 *
 * @param s The string to modify.
 * @param f The function to apply.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	counter = 0;
	while (s[counter])
	{
		(*f)(counter, &s[counter]);
		counter++;
	}
}
