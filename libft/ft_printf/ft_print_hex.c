/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptinf_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:00:14 by brunmigu          #+#    #+#             */
/*   Updated: 2025/05/04 09:02:04 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_hex(unsigned long nbr, char *base)
{
	int		counter;
	size_t	base_len;

	counter = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		counter += ft_print_hex(nbr / base_len, base);
	counter += ft_print_char(base[nbr % base_len]);
	return (counter);
}
