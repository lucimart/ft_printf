/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:43:58 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 18:38:22 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;
	size_t	content_len;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
	{
		content_len = ft_strlen((char *)content);
		if (!(node->content = (void *)malloc(content_len)))
			return (NULL);
		ft_memmove(node->content, content, content_len);
	}
	node->next = NULL;
	return (node);
}
