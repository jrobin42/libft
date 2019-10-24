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
DIR_INC:= include/
DIR_OBJ:= obj/

DIR_STR:= string/
DIR_SRC_STR:= $(DIR_STR)$(DIR_SRC)
DIR_INC_STR:= $(DIR_SRC)$(DIR_STR)$(DIR_INC)

DIR_PUT:= output/
DIR_SRC_PUT:= $(DIR_PUT)$(DIR_SRC)
DIR_INC_PUT:= $(DIR_SRC)$(DIR_PUT)$(DIR_INC)

DIR_MEM:= memory/
DIR_SRC_MEM:= $(DIR_MEM)$(DIR_SRC)
DIR_INC_MEM:= $(DIR_SRC)$(DIR_MEM)$(DIR_INC)

DIR_INT:= integer/
DIR_SRC_INT:= $(DIR_INT)$(DIR_SRC)
DIR_INC_INT:= $(DIR_SRC)$(DIR_INT)$(DIR_INC)

DIR_LST:= list/
DIR_SRC_LST:= $(DIR_LST)$(DIR_SRC)
DIR_INC_LST:= $(DIR_SRC)$(DIR_LST)$(DIR_INC)

DIR_PRINTF:= ft_printf/
DIR_SRC_PRINTF:= $(DIR_PUT)$(DIR_PRINTF)$(DIR_SRC)
DIR_INC_PRINTF:= $(DIR_SRC)$(DIR_PUT)$(DIR_PRINTF)$(DIR_INC)


SRC_BASE=	$(DIR_SRC_INT)ft_itoa.c \
			$(DIR_SRC_INT)ft_itoa_base.c \
			$(DIR_SRC_INT)ft_ultoa_base.c \
			$(DIR_SRC_INT)ft_power.c \
			$(DIR_SRC_INT)ft_sqrt.c \
			$(DIR_SRC_INT)ft_tolower.c \
			$(DIR_SRC_INT)ft_toupper.c \
			$(DIR_SRC_INT)ft_wchar_t.c \
			$(DIR_SRC_INT)ft_absolute.c \
			\
            $(DIR_SRC_STR)ft_isalnum.c \
            $(DIR_SRC_STR)ft_isalpha.c \
            $(DIR_SRC_STR)ft_isascii.c \
            $(DIR_SRC_STR)ft_isdigit.c \
            $(DIR_SRC_STR)ft_islower.c \
            $(DIR_SRC_STR)ft_isupper.c \
            $(DIR_SRC_STR)ft_isprint.c \
            $(DIR_SRC_STR)ft_isspace.c \
            $(DIR_SRC_STR)ft_isint.c \
			$(DIR_SRC_STR)ft_strdel.c \
			$(DIR_SRC_STR)get_next_line.c \
			$(DIR_SRC_STR)ft_atoi.c \
			$(DIR_SRC_STR)ft_freejoin.c \
			$(DIR_SRC_STR)ft_reverse.c \
			$(DIR_SRC_STR)ft_strlen.c \
			$(DIR_SRC_STR)ft_strdup.c \
			$(DIR_SRC_STR)ft_strcpy.c \
			$(DIR_SRC_STR)ft_strncpy.c \
			$(DIR_SRC_STR)ft_strchr.c \
			$(DIR_SRC_STR)ft_strrchr.c \
			$(DIR_SRC_STR)ft_strstr.c \
			$(DIR_SRC_STR)ft_strnstr.c \
			$(DIR_SRC_STR)ft_strcmp.c \
			$(DIR_SRC_STR)ft_strncmp.c \
			$(DIR_SRC_STR)ft_strcat.c \
			$(DIR_SRC_STR)ft_strncat.c \
			$(DIR_SRC_STR)ft_strsplit.c \
			$(DIR_SRC_STR)ft_strsub.c \
			$(DIR_SRC_STR)ft_strtrim.c \
			$(DIR_SRC_STR)ft_strjoin.c \
			$(DIR_SRC_STR)ft_strnew.c \
			$(DIR_SRC_STR)ft_strclr.c \
			$(DIR_SRC_STR)ft_striter.c \
			$(DIR_SRC_STR)ft_striteri.c \
			$(DIR_SRC_STR)ft_strmap.c \
			$(DIR_SRC_STR)ft_strmapi.c \
			$(DIR_SRC_STR)ft_strequ.c \
			$(DIR_SRC_STR)ft_strnequ.c \
			$(DIR_SRC_STR)countchar.c \
			\
			$(DIR_SRC_MEM)ft_bzero.c \
			$(DIR_SRC_MEM)ft_memalloc.c \
			$(DIR_SRC_MEM)ft_memset.c \
			$(DIR_SRC_MEM)ft_memmove.c \
			$(DIR_SRC_MEM)ft_memcpy.c \
			$(DIR_SRC_MEM)ft_memccpy.c \
			$(DIR_SRC_MEM)ft_memchr.c \
			$(DIR_SRC_MEM)ft_memcmp.c \
			$(DIR_SRC_MEM)ft_free_tab.c \
			$(DIR_SRC_MEM)ft_memdel.c \
			\
			$(DIR_SRC_PRINTF)all_opt.c \
			$(DIR_SRC_PRINTF)check.c \
			$(DIR_SRC_PRINTF)ft_printf.c \
			$(DIR_SRC_PRINTF)options_di.c \
			$(DIR_SRC_PRINTF)parse_percent.c \
			$(DIR_SRC_PRINTF)percent.c \
			$(DIR_SRC_PRINTF)trad_percent.c \
			$(DIR_SRC_PRINTF)type_c.c \
			$(DIR_SRC_PRINTF)type_cc.c \
			$(DIR_SRC_PRINTF)type_di.c \
			$(DIR_SRC_PRINTF)type_p.c \
			$(DIR_SRC_PRINTF)type_s.c \
			$(DIR_SRC_PRINTF)type_ss.c \
			$(DIR_SRC_PRINTF)type_uo.c \
			$(DIR_SRC_PRINTF)type_x.c \
			\
			$(DIR_SRC_PUT)ft_putchar.c \
			$(DIR_SRC_PUT)ft_putchar_fd.c \
			$(DIR_SRC_PUT)ft_putendl.c \
			$(DIR_SRC_PUT)ft_putendl_fd.c \
			$(DIR_SRC_PUT)ft_putnbr.c \
			$(DIR_SRC_PUT)ft_putnbr_fd.c \
			$(DIR_SRC_PUT)ft_putstr.c \
			$(DIR_SRC_PUT)ft_putstr_fd.c \
			\
			$(DIR_SRC_LST)ft_lstadd.c \
			$(DIR_SRC_LST)ft_lstadd_end.c \
			$(DIR_SRC_LST)ft_lstdel.c \
			$(DIR_SRC_LST)ft_lstdelone.c \
			$(DIR_SRC_LST)ft_lstiter.c \
			$(DIR_SRC_LST)ft_lstnew.c \
			$(DIR_SRC_LST)ft_lstnew_na.c \
			$(DIR_SRC_LST)ft_lstmap.c \
		 	$(DIR_SRC_LST)lst_insert_sort.c
			
INC=		-I $(DIR_INC_INT) \
            -I $(DIR_INC_STR) \
            -I $(DIR_INC_MEM) \
            -I $(DIR_INC_PRINTF) \
            -I $(DIR_INC_PUT) \
            -I $(DIR_INC_LST)


OBJS= $(addprefix $(DIR_OBJ), $(SRC_BASE:.c=.o))

all: Makefile
	@make -j $(NAME)

$(NAME): $(DIR_OBJ) $(OBJS) Makefile
	@ar rc $(NAME) $(OBJS)
	@echo "\033[32mThe lib is ready !\033[0m"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(dir $(OBJS))

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(FLAGS) $(INC) -MMD -c $< -o $@

clean:
	@rm -rf $(DIR_OBJ)
	@echo "\033[33mObjects deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mBinary deleted\033[0m"

re: fclean all

.PHONY :	clean fclean re all
