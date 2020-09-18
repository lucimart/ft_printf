/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:35:10 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/15 20:40:35 by lucimart         ###   ########.fr       */
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
		ret += write(1, str_nbr, data->prec);
		ret += write_width(data->width, data->prec, data->zero);
	}
	else
	{
		ret += write_width(data->width, data->prec, data->zero);
		ret += write(1, str_nbr, data->prec);
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
	str_nbr = ft_maxtoa((intmax_t)nbr, 10, 0);
	ret += write_u_aux(str_nbr, data);
	free(str_nbr);
	return (ret);
}
