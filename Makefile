# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 19:28:47 by jrobin            #+#    #+#              #
#    Updated: 2018/04/29 02:15:45 by jrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libft.a

CC=		gcc
FLAGS=	-Wall -Wextra -Werror

DIR_SRC:= src/
DIR_OBJ:= obj/

SRC_BASE=	ft_int/ft_itoa.c \
			ft_int/ft_itoa_base.c \
			ft_int/ft_ultoa_base.c \
			ft_int/ft_power.c \
			ft_int/ft_sqrt.c \
			ft_int/ft_tolower.c \
			ft_int/ft_toupper.c \
			ft_int/ft_wchar_t.c \
			ft_int/ft_absolute.c \
			\
			ft_str/get_next_line.c \
			ft_str/ft_atoi.c \
			ft_str/ft_bzero.c \
			ft_str/ft_freejoin.c \
			ft_str/ft_reverse.c \
			ft_str/ft_strlen.c \
			ft_str/ft_strdup.c \
			ft_str/ft_strcpy.c \
			ft_str/ft_strncpy.c \
			ft_str/ft_strchr.c \
			ft_str/ft_strrchr.c \
			ft_str/ft_strstr.c \
			ft_str/ft_strnstr.c \
			ft_str/ft_strcmp.c \
			ft_str/ft_strncmp.c \
			ft_str/ft_strcat.c \
			ft_str/ft_strncat.c \
			ft_str/ft_strsplit.c \
			ft_str/ft_strsub.c \
			ft_str/ft_strtrim.c \
			ft_str/ft_strjoin.c \
			ft_str/ft_strnew.c \
			ft_str/ft_strclr.c \
			ft_str/ft_striter.c \
			ft_str/ft_striteri.c \
			ft_str/ft_strmap.c \
			ft_str/ft_strmapi.c \
			ft_str/ft_strequ.c \
			ft_str/ft_strnequ.c \
			\
			ft_mem/ft_memalloc.c \
			ft_mem/ft_memset.c \
			ft_mem/ft_memmove.c \
			ft_mem/ft_memcpy.c \
			ft_mem/ft_memccpy.c \
			ft_mem/ft_memchr.c \
			ft_mem/ft_memcmp.c \
			\
			ft_clear/ft_strdel.c \
			ft_clear/ft_free_tab.c \
			ft_clear/ft_memdel.c \
			\
			ft_istype/ft_isalnum.c \
			ft_istype/ft_isalpha.c \
			ft_istype/ft_isascii.c \
			ft_istype/ft_isdigit.c \
			ft_istype/ft_islower.c \
			ft_istype/ft_isupper.c \
			ft_istype/ft_isprint.c \
			\
			ft_printf/all_opt.c \
			ft_printf/check.c \
			ft_printf/ft_printf.c \
			ft_printf/options_di.c \
			ft_printf/parse_percent.c \
			ft_printf/percent.c \
			ft_printf/trad_percent.c \
			ft_printf/type_c.c \
			ft_printf/type_cc.c \
			ft_printf/type_di.c \
			ft_printf/type_p.c \
			ft_printf/type_s.c \
			ft_printf/type_ss.c \
			ft_printf/type_uo.c \
			ft_printf/type_x.c \
			\
			ft_put/ft_putchar.c \
			ft_put/ft_putchar_fd.c \
			ft_put/ft_putendl.c \
			ft_put/ft_putendl_fd.c \
			ft_put/ft_putnbr.c \
			ft_put/ft_putnbr_fd.c \
			ft_put/ft_putstr.c \
			ft_put/ft_putstr_fd.c \
			\
			ft_istype/ft_isalnum.c \
			ft_istype/ft_isalpha.c \
			ft_istype/ft_isascii.c \
			ft_istype/ft_isdigit.c \
			ft_istype/ft_islower.c \
			ft_istype/ft_isupper.c \
			ft_istype/ft_isprint.c \
			ft_istype/ft_isspace.c \
			ft_istype/ft_isint.c \
			\
			ft_lst/ft_lstadd.c \
			ft_lst/ft_lstadd_end.c \
			ft_lst/ft_lstdel.c \
			ft_lst/ft_lstdelone.c \
			ft_lst/ft_lstiter.c \
			ft_lst/ft_lstnew.c \
			ft_lst/ft_lstnew_na.c \
			ft_lst/ft_lstmap.c \
			ft_lst/lst_insert_sort.c
			
INC=		libft.h


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
	$(CC) $(FLAGS) -I includes/ -MMD -c $< -o $@  

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY :	clean fclean re DEBUG
