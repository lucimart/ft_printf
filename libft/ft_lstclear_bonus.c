/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:01:59 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/21 12:29:32 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;
	t_list *aux;

	node = *lst;
	while (node)
	{
		aux = node;
		node = node->next;
		del(aux->content);
		free(aux);
	}
	*lst = NULL;
}
