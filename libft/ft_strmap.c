/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:12:44 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 22:59:07 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	if (s && f)
	{
		i = -1;
		if (!(fresh = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[++i])
			fresh[i] = f(s[i]);
		return (fresh);
	}
	else
		return (NULL);
}
