/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:53:15 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/21 17:21:49 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Receives the format struct, arg list, index position of data->str
** and a param to denote if its precision or not (width)
** Auxiliary function that parses digits or '*' char to assign the
** data->width or data->prec
*/

int		parse_digit(t_format *data, va_list arg, int i, int is_prec)
{
	i += is_prec == 1 ? 1 : 0;
	if (data->str[i] == '*')
	{
		if (is_prec && (data->prec = va_arg(arg, int)))
			data->prec = (data->prec < 0) ? 0 : data->prec;
		else
		{
			data->width = va_arg(arg, int);
			if (data->width < 0 && (data->minus = 1) && (data->width *= -1))
				(data->zero = 0);	
		}
		i++;
	}
	else if (ft_strchr("0123456789", data->str[i]))
		while (ft_strchr("0123456789", data->str[i]))
		{
			if (is_prec)
				data->prec = (data->prec * 10) + (data->str[i++] - '0');
			else
				data->width = (data->width * 10) + (data->str[i++] - '0');
		}
	else if (is_prec)
		data->zero = 0;
	return (--i);
}

/*
** Parses from the start of the '%' char until the end
** of its flags (of the mandatory part). To assign values
** to the `data` t_format struct.
*/

int		parser(t_format *data, va_list arg, int i)
{
	while (ft_strchr("-0.*123456789cspdiuxX%", data->str[++i]))
	{
		if (data->str[i] == '-' && !data->minus && (data->minus = 1))
			data->zero = 0;
		else if (data->str[i] == '0' && !data->width && !data->minus
			&& !data->zero)
			data->zero = 1;
		else if (ft_strchr("0123456789*", data->str[i]) && !data->width
			&& !data->prec)
			i = parse_digit(data, arg, i, 0);
		else if (data->str[i] == '.' && !data->prec)
			i = parse_digit(data, arg, i, 1);
		else if (in_set(data->str[i], "cspdiuxX%"))
		{
			data->type = ft_strchr("cspdiuxX%", data->str[i])[0];
			break ;
		}
	}
	return (i);
}
