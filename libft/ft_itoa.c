/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:15:14 by brunmigu          #+#    #+#             */
/*   Updated: 2025/04/15 17:16:40 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_len(int n);

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		nbr_len;

	nbr = n;
	nbr_len = ft_int_len(n);
	result = ft_calloc(nbr_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (nbr == 0)
		return (result[0] = '0', result[1] = '\0', result);
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	result[nbr_len] = '\0';
	while (nbr > 0)
	{
		result[--nbr_len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (result);
}

int	ft_int_len(int n)
{
	int		counter;
	long	nbr;

	nbr = n;
	counter = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		counter ++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}
/*
int	main(void)
{
	int		nbr;
	char	*str;

	nbr = -1234;
	str = ft_itoa(nbr);
	printf("%s", str);
	free(str);
}*/
