/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:07:33 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/18 18:45:10 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Function that handles the call of the appropiate
** function to format, depending on the data->type
** and returns the number of printed bytes in `ret`
*/

int		form(t_format *data, va_list arg)
{
	int ret;

	ret = 0;
	if (data->type == 'c')
		ret += write_c(va_arg(arg, int), data);
	else if (data->type == 's')
		ret += write_s(va_arg(arg, char *), data);
	else if (data->type == 'p')
		ret += write_p(va_arg(arg, unsigned long long), data);
	else if (in_set(data->type, "di"))
		ret += write_d(va_arg(arg, int), data);
	else if (data->type == 'u')
		ret += write_u((unsigned int)va_arg(arg, unsigned int), data);
	else if (data->type == 'x')
		ret += write_x(va_arg(arg, unsigned int), data, 0);
	else if (data->type == 'X')
		ret += write_x(va_arg(arg, unsigned int), data, 1);
	else if (data->type == '%')
		ret += write_mod();
	return (ret);
}

/*
** Auxiliary function that writes the width (either zeroed or spaced)
** in case there is one needed
** Returns the number of total printed bytes, `ret`
** TODO left aligned?
*/

int		write_width(int width, int minus, int zero)
{
	int ret;

	ret = 0;
	minus = 0;
	while (width-- - minus)
		ret += write(1, (zero ? "0" : " "), 1);
	return (ret);
}
