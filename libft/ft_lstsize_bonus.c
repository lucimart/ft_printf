/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 00:18:36 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/13 22:22:09 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*node;

	node = lst;
	size = 0;
	if (!node)
		return (0);
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
