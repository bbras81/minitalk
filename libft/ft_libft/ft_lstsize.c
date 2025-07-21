/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:27:53 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:20:13 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		counter;

	temp = lst;
	counter = 0;
	while (temp)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
