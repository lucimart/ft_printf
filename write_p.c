/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:37:05 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/22 20:45:21 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Aux function for %p, actually does the printing stuff.
*/

int	write_p_aux(char *str, t_format *data, int len)
{
	int ret;

	ret = 0;
	data->prec = (data->prec_omit) ? 0 : data->prec;
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

	str = ft_strdup("0x");
	if (data->dot && (data->prec == 0) && (nbr == 0))
		len = 2;
	else
	{
		len = ft_strlen(ft_umaxtoa(nbr, 16, 0)) + 3;
		ft_strlcat(str, ft_umaxtoa(nbr, 16, 0), len--);
	}
	ret = write_p_aux(str, data, len);
	free(str);
	return (ret);
}
