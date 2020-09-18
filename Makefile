# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucimart <lucimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 23:50:14 by lucimart          #+#    #+#              #
#    Updated: 2020/09/18 19:01:57 by lucimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =			libftprintf.a

CC =			gcc
FLAGS =			-g -Wall -Werror -Wextra

LIBFT_DIR =		./libft/
LIBFT_H =		$(LIBFT_DIR)libft.h
LIBFT_O =		ft_strdup.o \
				ft_substr.o \
				ft_strtrim.o \
				ft_strmap.o \
				ft_strlen.o \
				ft_putstr_fd.o \
				ft_strjoin.o \
				ft_memset.o \
				ft_putnbr.o \
				in_set.o \
				ft_itoa.o \
				ft_putstr.o \
				ft_striteri.o \
				ft_striter.o \
				ft_split.o \
				ft_strnew.o \
				ft_memalloc.o \
				ft_putnbr_fd.o \
				ft_putendl.o \
				ft_putchar_fd.o \
				ft_strdel.o \
				ft_memdel.o \
				ft_strequ.o \
				ft_bzero.o \
				ft_putchar.o \
				ft_strnequ.o \
				ft_strclr.o \
				ft_putendl_fd.o \
				ft_strmapi.o \
				ft_calloc.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_strncpy.o \
				ft_strlcpy.o \
				ft_isalpha.o \
				ft_isdigit.o \
				ft_isalnum.o \
				ft_isascii.o \
				ft_isprint.o \
				ft_toupper.o \
				ft_tolower.o \
				ft_atoi.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_strncmp.o \
				ft_strnstr.o \
				ft_maxtoa.o \
				ft_umaxtoa.o \
				ft_strlcat.o

PRINTF_H =		libftprintf.h
PRINTF_O =		ft_printf.o \
				parser.o \
				form.o \
				write_c.o \
				write_s.o \
				write_p.o \
				write_d.o \
				write_u.o \
				write_hex.o \
				write_mod.o

OBJ =			$(LIBFT_O) $(PRINTF_O)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(LIBFT_O): %.o: $(LIBFT_DIR)%.c $(LIBFT_H)
	$(CC) -c $(FLAGS) -I $(LIBFT_DIR) $< -o $@

$(PRINTF_O): %.o: %.c $(PRINTF_H)
	$(CC) -c $(FLAGS) -I $(LIBFT_DIR) $< -o $@

clean:
	-/bin/rm -f $(OBJ)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
