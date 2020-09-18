/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:27:24 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/07 22:53:24 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = -1;
	if (dstsize > dst_len)
		src_len += dst_len;
	else
		src_len += dstsize;
	while (src[++i] && (dst_len + i + 1) < dstsize)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (src_len);
}
