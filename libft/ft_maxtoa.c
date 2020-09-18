/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:48:11 by lucimart          #+#    #+#             */
/*   Updated: 2020/03/05 16:03:20 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_digits(intmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0 && ++i)
		n /= base;
	return (i);
}

char		*ft_maxtoa(intmax_t n, int base, int uppercase)
{
	char	*str;
	int		len;

	len = nbr_digits(n, base);
	if (!(str = ft_strnew(len--)))
		return (NULL);
	if (n < 0 && (n = -n))
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (base > 10 && (n % base >= 10))
			str[len--] = (n % base) - 10 + (uppercase ? 'A' : 'a');
		else
			str[len--] = (n % base) + '0';
		n /= base;
	}
	return (str);
}
