/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:15:29 by brunmigu          #+#    #+#             */
/*   Updated: 2025/05/04 08:24:33 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_udec(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
		counter += ft_print_udec(nb / 10);
	counter += ft_print_char((nb % 10) + 48);
	return (counter);
}
