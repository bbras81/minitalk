/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:08:44 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/19 17:10:54 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Converts a string to an long integer.
 *
 * @param nptr The string to convert.
 * @return int The converted long integer value.
 */

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			sign *= -1;
		}
		nptr++;
	}
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		nbr *= 10;
		nbr += *nptr - 48;
		nptr++;
	}
	return (nbr * sign);
}
