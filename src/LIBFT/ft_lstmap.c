/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:41:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 13:08:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_list	*ft_free_node(t_list *head, void *tmp, void (*del)(void *))
{
	ft_lstclear(&head, del);
	del(tmp);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;
	void	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst->content);
	head = ft_lstnew(tmp);
	if (!head)
		return (ft_free_node(head, tmp, del));
	cur = head;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst->content);
		cur->next = ft_lstnew(tmp);
		if (!cur->next)
			return (ft_free_node(head, tmp, del));
		cur = cur->next;
	}
	return (head);
}
