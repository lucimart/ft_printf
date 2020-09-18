/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:05:30 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 23:06:43 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*casted_src;
	char	*casted_dest;
	size_t	i;

	if (!n || (src == dest))
		return (dest);
	i = -1;
	casted_src = (char *)src;
	casted_dest = (char *)dest;
	while (++i < n)
		casted_dest[i] = casted_src[i];
	return (dest);
}
