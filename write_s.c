/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:28:30 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/15 20:51:54 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** TODO write description
*/

int	write_s(char *str, t_format *data)
{
	int ret;
	int len;

	if (!str)
		str = "(null)";
	ret = 0;
	len = ft_strlen(str);
	data->prec = (data->prec >= 0 && data->prec < len) ? data->prec : len;
	data->width = data->width > data->prec ? (data->width - data->prec) : 0;
	if (data->minus)
	{
		ret += write_width(data->width, data->prec, 0);
		ret += write(1, str, data->prec);
	}
	else
	{
		ret += write(1, str, data->prec);
		ret += write_width(data->width, data->prec, 0);
	}
	return (ret);
}
