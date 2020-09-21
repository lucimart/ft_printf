/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 01:33:32 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/22 01:00:17 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function assigns the original
** string to be formatted (`str`). To the
** newly created struct (`data`) in its
** `data->str` member, as per defined
** in the libftprintf.h
*/

void	init(t_format *data, char *str)
{
	data->str = ft_strdup(str);
}

/*
** Reset the struct members to a initial value
** So to proceed to format a next part.
*/

void	reset_flags(t_format *data)
{
	data->type = 0;
	data->minus = 0;
	data->zero = 0;
	data->width = 0;
	data->prec = 0;
	data->prec_omit = 0;
	data->dot = 0;
}

/*
** Auxiliary function to ft_printf.
** `i` is the index while iterating the string to be
** formatted. `ret` is the value of return of ft_printf
*/

int		printf_aux(t_format *data, va_list arg)
{
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (data->str[++i])
	{
		if (data->str[i] != '%')
			ret += write(1, (data->str + i), 1);
		else if (data->str[i + 1])
		{
			reset_flags(data);
			i = parser(data, arg, i);
			if (in_set(data->str[i], "cspdiuxX%"))
				ret += form(data, arg);
			else if (data->str[i])
				ret += write(1, (data->str + i), 1);
		}
	}
	return (ret);
}

/*
** The first argument is the string to print formatted
** the following arguments (...) are the parameters to
** format according to `format`. The return value is negative
** if an error is found. Upon successful return, these functions
** return the number of characters printed.
*/

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_format	*data;
	int			ret;

	if (!(data = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	init(data, (char *)format);
	va_start(arg, format);
	ret = printf_aux(data, arg);
	va_end(arg);
	free(data);
	return (ret);
}
