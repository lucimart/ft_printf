/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:18:21 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/22 01:18:22 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Formats the %c type. Returns the total bytes wrote
** in `ret`. If data->minus, left aligned, else right aligned.
** Sums a last 1 to ret per the char printed.
*/

int	write_c(char c, t_format *data)
{
	int ret;
	int len;

	len = 1;
	ret = 0;
	data->prec = (data->prec_omit) ? 0 : data->prec;
	data->prec = (data->prec >= 0 && data->prec < len) ? len : data->prec;
	data->width = data->width > data->prec ? (data->width - data->prec) : 0;
	if (data->minus)
	{
		ret += write_zeroes(data, len);
		write(1, &c, 1);
		ret = write_spaces(data, len);
	}
	else
	{
		ret += write_spaces(data, len);
		ret += write_zeroes(data, len);
		write(1, &c, 1);
	}
	return (++ret);
}
