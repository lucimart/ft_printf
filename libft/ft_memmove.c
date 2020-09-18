/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 23:26:05 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 23:03:40 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*casted_src;
	unsigned char	*casted_dest;
	size_t			i;

	if (!n || dest == src)
		return (dest);
	casted_src = (unsigned char *)src;
	casted_dest = (unsigned char *)dest;
	i = -1;
	if (casted_src > casted_dest)
		while (++i < n)
			casted_dest[i] = casted_src[i];
	else
		while (n-- > 0)
			casted_dest[n] = casted_src[n];
	return (dest);
}
