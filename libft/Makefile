#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lucimart <lucimart@student.42madrid.com>   +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/11/03 17:03:05 by lucimart          #+#    #+#             *#
#*   Updated: 2019/11/27 18:14:18 by lucimart         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
NAME = libft.a
SRCS = ft_strdup.c \
	   ft_substr.c \
	   ft_strtrim.c \
	   ft_strmap.c \
	   ft_strlen.c \
	   ft_putstr_fd.c \
	   ft_strjoin.c \
	   ft_memset.c \
	   ft_putnbr.c \
	   in_set.c \
	   ft_itoa.c \
	   ft_putstr.c \
	   ft_striteri.c \
	   ft_striter.c \
	   ft_split.c \
	   ft_strnew.c \
	   ft_memalloc.c \
	   ft_putnbr_fd.c \
	   ft_putendl.c \
	   ft_putchar_fd.c \
	   ft_strdel.c \
	   ft_memdel.c \
	   ft_strequ.c \
	   ft_bzero.c \
	   ft_putchar.c \
	   ft_strnequ.c \
	   ft_strclr.c \
	   ft_putendl_fd.c \
	   ft_strmapi.c \
	   ft_calloc.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strncpy.c \
	   ft_strlcpy.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_atoi.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_maxtoa.c \
	   ft_umaxtoa.c \
	   ft_strlcat.c
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)
BON_SRC = ft_lstnew_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c
BON_OBJ = $(SRCS:.c=.o) $(BON_SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(BON_OBJ)
	ar rc $(NAME) $(BON_OBJ)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gch
	/bin/rm -f *.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -I  $(HEADER) -c $< -o $@
