/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:37:05 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/21 21:17:37 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Receives the unsigned long long `nbr` which
** will be converted into base 16 using own function
** ft_umaxtoa, then standard procedure to print
** and returns `ret` which is number of bytes written.
*/

int	write_p(unsigned long long nbr, t_format *data)
{
	char	*str;
	int		ret;
	int		len;

	ret = 0;
	str = (nbr != 0) ? ft_strdup("0x") : ft_strdup("(nil)");
	len = (nbr != 0) ? ft_strlen(ft_umaxtoa(nbr, 16, 0)) + 3 : 5;
	if (nbr != 0)
		ft_strlcat(str, ft_umaxtoa(nbr, 16, 0), len--);
	data->prec = (data->prec >= 0 && data->prec < len) ? len : data->prec;
	data->width = data->width > data->prec ? (data->width - data->prec) : 0;
	if (data->minus)
	{
		ret += write_zeroes(data, len);
		ret += write(1, str, len);
		ret += write_spaces(data, len);
	}
	else
	{
		ret += write_spaces(data, len);
		ret += write_zeroes(data, len);
		ret += write(1, str, len);
	}
	free(str);
	return (ret);
}
