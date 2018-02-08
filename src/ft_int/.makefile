# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 19:28:47 by jrobin            #+#    #+#              #
#    Updated: 2018/02/07 22:19:17 by jrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft_int.a

DIR_SRC:= src/
DIR_OBJ:= obj/
DIR_INC:= inc/
DIR_INC_LIB:= ../inc/

SRC=	ft_itoa.c \
		ft_itoa_base.c \
		ft_ultoa_base.c \
		ft_power.c \
		ft_sqrt.c \
		ft_tolower.c \
		ft_wchar_t.c \
		ft_toupper.c \

INC=	libft_int.h

SRCS= $(addprefix $(DIR_SRC), $(SRC))
SRCS_INT= $(addprefix $(PATH_INT), $(SRC_INT)))
SRCS_STR= $(addprefix $(PATH_STR), $(SRC_STR)))
OBJS= $(addprefix $(DIR_OBJ), $(SRC:.c=.o))
INCS= $(addprefix $(DIR_INC), $(INC))

all: $(NAME)

$(NAME): INIT $(INCS) $(OBJS)
	ar rc $(NAME) $(OBJS)

DEBUG: 
	echo $(SRCS)
	echo $(OBJS)

INIT: 
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	gcc -c -I $(DIR_INC) -I $(DIR_INC_LIB) -Wall -Wextra -Werror -o $@ $<

clean:
	rm -rf $(DIR_OBJ)

fclean:
	rm -f $(NAME)
	rm -rf $(DIR_OBJ)

re: fclean
	make
