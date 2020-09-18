/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:00:52 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/27 18:19:05 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s || !(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	str[i] = '\0';
	return (str);
}
