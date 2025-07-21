/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:16:05 by brunmigu          #+#    #+#             */
/*   Updated: 2025/05/02 16:23:36 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_str(char *str)
{
	int	counter;

	counter = -1;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[++counter])
	{
		ft_putchar_fd(str[counter], 1);
	}
	return (counter);
}
