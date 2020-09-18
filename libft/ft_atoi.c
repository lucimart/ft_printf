/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 02:40:39 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/07 00:13:34 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (in_set(*nptr, " \n\t\v\f\r"))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = (*nptr++ == '-') ? -1 : 1;
	while (*nptr >= '0' && *nptr <= '9')
		nbr = (nbr * 10) + (*nptr++ - '0');
	return (nbr * sign);
}
