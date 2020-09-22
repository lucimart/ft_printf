/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:35:10 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/22 20:03:01 by lucimart         ###   ########.fr       */
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
	data->prec = ((data->prec >= 0 && data->prec < len) || data->prec_omit) ?
		len : data->prec;
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
	str_nbr = (data->dot && (data->prec == 0) && (nbr == 0)) ?
		ft_strdup("") : ft_maxtoa((intmax_t)nbr, 10, 0);
	ret += write_u_aux(str_nbr, data);
	free(str_nbr);
	return (ret);
}
