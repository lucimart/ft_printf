/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:18:21 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/15 20:51:26 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Formats the %c type. Returns the total bytes wrote
** in `ret`. If data->minus, left aligned, else right aligned.
** Sums a last 1 to ret per the char printed.
*/

int	write_c(char c, t_format *data)
{
	int ret;

	ret = 0;
	if (data->minus)
	{
		write(1, &c, 1);
		ret = write_width(data->width, 1, 0);
	}
	else
	{
		ret = write_width(data->width, 1, 0);
		write(1, &c, 1);
	}
	return (++ret);
}
