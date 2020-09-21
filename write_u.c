/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:35:10 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/22 00:53:55 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Aux function. Returns total number of bytes written.
** Actually writes the nbr (now a string)
*/

static int	write_u_aux(char *str_nbr, t_format *data)
{
	int ret;
	int len;

	ret = 0;
	len = ft_strlen(str_nbr);
	data->prec = (data->prec >= 0 && data->prec < len) ? len : data->prec;
	data->width = data->width > data->prec ? (data->width - data->prec) : 0;
	if (data->minus)
	{
		ret += write_zeroes(data, len);
		ret += write(1, str_nbr, len);
		ret += write_spaces(data, len);
	}
	else
	{
		ret += write_spaces(data, len);
		ret += write_zeroes(data, len);
		ret += write(1, str_nbr, len);
	}
	return (ret);
}

/*
** Returns total number of bytes written
** assigns the number as a string, then calls aux
*/

int			write_u(unsigned int nbr, t_format *data)
{
	char	*str_nbr;
	int		ret;

	ret = 0;
	data->prec = (data->prec_omit) ? 0 : data->prec;
	str_nbr = ft_maxtoa((intmax_t)nbr, 10, 0);
	ret += write_u_aux(str_nbr, data);
	free(str_nbr);
	return (ret);
}
