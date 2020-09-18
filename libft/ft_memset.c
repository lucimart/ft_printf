/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:33:03 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 23:04:48 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*str;
	unsigned char	ch;
	size_t			i;

	str = (char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
		str[i++] = ch;
	return (s);
}
