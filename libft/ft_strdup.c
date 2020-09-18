/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 00:31:26 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/05 18:03:36 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!(dup = ft_strnew(ft_strlen(s))) || !s)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	return (dup);
}
