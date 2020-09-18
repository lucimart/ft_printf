/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:44:54 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/03 22:52:18 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!(s1 && s2))
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		n--;
	}
	return (1);
}
