/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:45:19 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/15 20:45:58 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Lmao does this needs explanation?
** Writes '%' and returns the number
** of bytes written (hint: 1)
*/

int		write_mod(void)
{
	write(1, "%", 1);
	return (1);
}
