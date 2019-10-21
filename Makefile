# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 19:28:47 by jrobin            #+#    #+#              #
#    Updated: 2018/04/30 16:17:14 by jrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libft.a

CC=		gcc
FLAGS=	-Wall -Wextra -Werror

DIR_SRC:= src/
DIR_OBJ:= obj/

SRC_BASE=	ft_int/src/ft_itoa.c \
			ft_int/src/ft_itoa_base.c \
			ft_int/src/ft_ultoa_base.c \
			ft_int/src/ft_power.c \
			ft_int/src/ft_sqrt.c \
			ft_int/src/ft_tolower.c \
			ft_int/src/ft_toupper.c \
			ft_int/src/ft_wchar_t.c \
			ft_int/src/ft_absolute.c \
			\
			ft_str/src/get_next_line.c \
			ft_str/src/ft_atoi.c \
			ft_str/src/ft_freejoin.c \
			ft_str/src/ft_reverse.c \
			ft_str/src/ft_strlen.c \
			ft_str/src/ft_strdup.c \
			ft_str/src/ft_strcpy.c \
			ft_str/src/ft_strncpy.c \
			ft_str/src/ft_strchr.c \
			ft_str/src/ft_strrchr.c \
			ft_str/src/ft_strstr.c \
			ft_str/src/ft_strnstr.c \
			ft_str/src/ft_strcmp.c \
			ft_str/src/ft_strncmp.c \
			ft_str/src/ft_strcat.c \
			ft_str/src/ft_strncat.c \
			ft_str/src/ft_strsplit.c \
			ft_str/src/ft_strsub.c \
			ft_str/src/ft_strtrim.c \
			ft_str/src/ft_strjoin.c \
			ft_str/src/ft_strnew.c \
			ft_str/src/ft_strclr.c \
			ft_str/src/ft_striter.c \
			ft_str/src/ft_striteri.c \
			ft_str/src/ft_strmap.c \
			ft_str/src/ft_strmapi.c \
			ft_str/src/ft_strequ.c \
			ft_str/src/ft_strnequ.c \
			ft_str/src/countchar.c \
			\
			ft_mem/src/ft_bzero.c \
			ft_mem/src/ft_memalloc.c \
			ft_mem/src/ft_memset.c \
			ft_mem/src/ft_memmove.c \
			ft_mem/src/ft_memcpy.c \
			ft_mem/src/ft_memccpy.c \
			ft_mem/src/ft_memchr.c \
			ft_mem/src/ft_memcmp.c \
			\
			ft_clear/src/ft_strdel.c \
			ft_clear/src/ft_free_tab.c \
			ft_clear/src/ft_memdel.c \
			\
			ft_istype/src/ft_isalnum.c \
			ft_istype/src/ft_isalpha.c \
			ft_istype/src/ft_isascii.c \
			ft_istype/src/ft_isdigit.c \
			ft_istype/src/ft_islower.c \
			ft_istype/src/ft_isupper.c \
			ft_istype/src/ft_isprint.c \
			\
			ft_printf/src/all_opt.c \
			ft_printf/src/check.c \
			ft_printf/src/ft_printf.c \
			ft_printf/src/options_di.c \
			ft_printf/src/parse_percent.c \
			ft_printf/src/percent.c \
			ft_printf/src/trad_percent.c \
			ft_printf/src/type_c.c \
			ft_printf/src/type_cc.c \
			ft_printf/src/type_di.c \
			ft_printf/src/type_p.c \
			ft_printf/src/type_s.c \
			ft_printf/src/type_ss.c \
			ft_printf/src/type_uo.c \
			ft_printf/src/type_x.c \
			\
			ft_put/src/ft_putchar.c \
			ft_put/src/ft_putchar_fd.c \
			ft_put/src/ft_putendl.c \
			ft_put/src/ft_putendl_fd.c \
			ft_put/src/ft_putnbr.c \
			ft_put/src/ft_putnbr_fd.c \
			ft_put/src/ft_putstr.c \
			ft_put/src/ft_putstr_fd.c \
			\
			ft_istype/src/ft_isalnum.c \
			ft_istype/src/ft_isalpha.c \
			ft_istype/src/ft_isascii.c \
			ft_istype/src/ft_isdigit.c \
			ft_istype/src/ft_islower.c \
			ft_istype/src/ft_isupper.c \
			ft_istype/src/ft_isprint.c \
			ft_istype/src/ft_isspace.c \
			ft_istype/src/ft_isint.c \
			\
			ft_lst/src/ft_lstadd.c \
			ft_lst/src/ft_lstadd_end.c \
			ft_lst/src/ft_lstdel.c \
			ft_lst/src/ft_lstdelone.c \
			ft_lst/src/ft_lstiter.c \
			ft_lst/src/ft_lstnew.c \
			ft_lst/src/ft_lstnew_na.c \
			ft_lst/src/ft_lstmap.c \
			ft_lst/src/lst_insert_sort.c
			
INC=		-I $(DIR_SRC)ft_int/include/ \
            -I $(DIR_SRC)ft_str/include/ \
            -I $(DIR_SRC)ft_mem/include/ \
            -I $(DIR_SRC)ft_clear/include/ \
            -I $(DIR_SRC)ft_istype/include/ \
            -I $(DIR_SRC)ft_printf/include/ \
            -I $(DIR_SRC)ft_put/include/ \
            -I $(DIR_SRC)ft_istype/include/ \
            -I $(DIR_SRC)ft_lst/include/


OBJS= $(addprefix $(DIR_OBJ), $(SRC_BASE:.c=.o))

all:
	@make -j $(NAME)

$(NAME): $(DIR_OBJ) $(OBJS) Makefile
	@ar rc $(NAME) $(OBJS)
	@echo "\033[32mlibft ok\033[0m"

DEBUG: 
	@echo $(OBJS)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(dir $(OBJS))

$(DIR_OBJ)%.o: $(DIR_SRC)%.c Makefile
	$(CC) $(FLAGS) $(INC) -MMD -c $< -o $@

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY :	clean fclean re DEBUG
