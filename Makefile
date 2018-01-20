# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 19:28:47 by jrobin            #+#    #+#              #
#    Updated: 2018/01/20 19:07:27 by jrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
SRC=			ft_sqrt.c \
				ft_reverse.c \
				ft_free_tab.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_memset.c \
				ft_bzero.c \
				\
				ft_memmove.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				\
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_strlen.c \
				ft_wchar_t.c \
				\
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strequ.c \
				ft_strnequ.c \
				\
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				\
				ft_strcat.c \
				ft_strncat.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strsub.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strdup.c \
				ft_strchr.c \
				ft_strrchr.c \
				\
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_islower.c \
				ft_isupper.c \
				\
				ft_atoi.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_ultoa_base.c \
				\
				ft_putnbr.c \
				ft_putnbr_fd.c \
				\
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				\
				ft_lstnew.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				\
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				lst_insert_sort.c \


OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean
	make
