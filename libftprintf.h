/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 02:38:52 by lucimart          #+#    #+#             */
/*   Updated: 2020/09/21 16:16:08 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_format
{
	char		*str;
	int			negNum;

	char		type;
	int			minus;
	int			zero;
	int			width;
	int			prec;
}				t_format;

int				ft_printf(const char *format, ...);
int				parser(t_format *data, va_list arg, int i);
int				form(t_format *data, va_list arg);
int				write_spaces(t_format *data, int len);
int				write_zeroes(t_format *data, int len);
int				write_c(char c, t_format *data);
int				write_s(char *str, t_format *data);
int				write_p(unsigned long long nbr, t_format *data);
int				write_d(int nbr, t_format *data);
int				write_u(unsigned int nbr, t_format *data);
int				write_x(unsigned int nbr, t_format *data, int uppercase);
int				write_mod(void);
#endif
