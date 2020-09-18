/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:19:23 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/27 03:25:06 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	list = lst;
	new_list = NULL;
	while (list)
	{
		if (!(node = ft_lstnew(f(list->content))))
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		list = list->next;
	}
	return (new_list);
}
