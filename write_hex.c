/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:41:22 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/21 20:49:49 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Aux function. Returns total number of bytes written.
** Actually writes the formatted number.
*/

static int		write_x_aux(char *str, t_format *data)
{
	int ret;
	int len;

	ret = 0;
	len = ft_strlen(str);
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
	return (ret);
}

/*
** Transforms the nbr in a base 16 string, depending
** if flag 'x' or 'X', `uppercase` will be 0 or 1
** Returns total number of bytes written.
*/

int				write_x(unsigned int nbr, t_format *data, int uppercase)
{
	char	*str;
	int		ret;

	ret = 0;
	str = ft_umaxtoa((uintmax_t)nbr, 16, uppercase);
	ret += write_x_aux(str, data);
	free(str);
	return (ret);
}
