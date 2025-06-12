/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:49 by brunmigu          #+#    #+#             */
/*   Updated: 2025/06/05 12:57:32 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getformat(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == '%')
		counter += ft_print_char('%');
	else if (c == 'c')
		counter += ft_print_char(va_arg(args, int));
	else if (c == 's')
		counter += ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		counter += ft_print_dec(va_arg(args, int));
	else if (c == 'u')
		counter += ft_print_udec(va_arg(args, unsigned int));
	else if (c == 'x')
		counter += ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		counter += ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		counter += ft_print_ptr(va_arg(args, void *));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	int		counter_ret;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	counter = -1;
	counter_ret = 0;
	while (str[++counter])
	{
		if (str[counter] == '%' && str[counter + 1] != '\n')
		{
			counter++;
			counter_ret += ft_getformat(str[counter], args);
		}
		else
		{
			ft_putchar_fd(str[counter], 1);
			counter_ret++;
		}
	}
	return (counter_ret);
}
