/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:48:11 by lucimart          #+#    #+#             */
/*   Updated: 2019/11/06 23:08:30 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_digits(int n)
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
		n /= 10;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = nbr_digits(n);
	if (!(str = ft_strnew(len--)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
