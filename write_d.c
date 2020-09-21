/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:09:35 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/21 17:12:21 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** aux function that actually writes the nbr (now a string)
** and returns the number of bytes written
*/

static int	write_d_aux(char *str_nbr, t_format *data)
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
** Receives nbr to format and struct.
** Returns total bytes written.
** First check if nbr is negative to handle cases
** then conver it to string, aux func, free and return.
*/

int			write_d(int nbr, t_format *data)
{
	char	*str_nbr;
	int		ret;

	ret = 0;
	if (nbr < 0 && data->zero)
	{
		data->negNum = 1;
		nbr *= -1;
		data->width--;
	}
	str_nbr = ft_itoa(nbr);
	ret += write_d_aux(str_nbr, data);
	free(str_nbr);
	return (ret);
}
