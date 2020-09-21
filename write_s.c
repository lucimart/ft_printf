/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:28:30 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/22 01:13:47 by lucimart         ###   ########.fr       */
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
		str = ft_strdup("(null)");
	ret = 0;
	len = ft_strlen(str);
	data->prec = (data->prec_omit) ? len : data->prec;
	data->prec = (data->dot) ? data->prec : len;
	data->prec = (data->prec >= 0 && data->prec < len) ? data->prec : len;
	data->prec = (ft_strequ(str, "(null)") && data->dot && !data->prec_omit) ?
		0 : data->prec;
	data->width = data->width > data->prec ? (data->width - data->prec) : 0;
	if (data->minus)
	{
		ret += write(1, str, data->prec);
		ret += write_spaces(data, data->prec);
	}
	else
	{
		ret += write_spaces(data, data->prec);
		ret += write(1, str, data->prec);
	}
	return (ret);
}
