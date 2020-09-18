/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:16:36 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 23:07:49 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*casted_src;
	unsigned char	*casted_dest;
	unsigned char	ch;
	size_t			i;

	casted_src = (unsigned char *)src;
	casted_dest = (unsigned char *)dest;
	ch = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		casted_dest[i] = casted_src[i];
		if (casted_src[i] == ch)
			return (dest + i + 1);
	}
	return (NULL);
}
