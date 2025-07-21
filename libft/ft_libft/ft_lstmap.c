/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:25:02 by brunmigu          #+#    #+#             */
/*   Updated: 2025/07/10 22:19:50 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*We want to create a new list with the content of the first list */
/*after applying the function f to each element of the list.*/
/*If the list is empty or the f or del is NULL, we return NULL.*/
/*We go through the list and apply the function f to each element of the list.*/
/*If the function f fails, we delete the new list and the content of the node.*/
/*We add the new node to the new list.*/
/**/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	void	*temp;
	t_list	*buffer_node;

	if (!lst || !f || !del)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		temp = (f)(lst->content);
		buffer_node = ft_lstnew(temp);
		if (!buffer_node)
		{
			del(temp);
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, buffer_node);
		lst = lst->next;
	}
	return (new_l);
}
