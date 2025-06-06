/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:52:54 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/05 12:57:45 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_print_dec(int nbr)
{
	int	counter;

	counter = 0;
	if (nbr == -2147483648)
		counter += ft_print_str("-2147483648");
	else
	{
		if (nbr < 0)
		{
			counter += ft_print_str("-");
			nbr *= -1;
		}
		if (nbr > 9)
		{
			counter += ft_print_dec(nbr / 10);
		}
		counter += ft_print_char((nbr % 10) + '0');
	}
	return (counter);
}
