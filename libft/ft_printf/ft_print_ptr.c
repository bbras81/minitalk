/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:15:56 by brunmigu          #+#    #+#             */
/*   Updated: 2025/05/04 12:27:34 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_ptr(void *ptr)
{
	int				counter;
	unsigned long	addr;

	if (!ptr)
		return (ft_print_str(("(nil)")));
	counter = 0;
	addr = (unsigned long)ptr;
	counter += ft_print_str("0x");
	counter += ft_print_hex(addr, "0123456789abcdef");
	return (counter);
}
