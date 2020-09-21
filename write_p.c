/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:37:05 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/21 14:45:30 by lucimart         ###   ########.fr       */
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

	ret = write(1, "0x", 2);
	str = ft_umaxtoa(nbr, 16, 0);
	len = ft_strlen(str);
	data->prec = (data->prec >= 0 && data->prec < len) ? len : data->prec;
	data->width = data->width > data->prec ? (data->width - data->prec) : 0;
	if (data->minus)
	{
		ret += write(1, str, data->prec);
		ret += write_spaces(data, len);
	}
	else
	{
		ret += write_spaces(data, len);
		ret += write(1, str, data->prec);
	}
	free(str);
	return (ret);
}
