# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/10/04 16:24:40 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
#-fsanitize=address

#FLAGS += -Wall -Wextra -Werror -fsanitize=address

SRC = main.c op.c store_file.c data_initializer.c file_manager.c \
ft_iscomment.c recovery.c display.c header_manager.c name_manager.c\
comment_manager.c error.c free_all_data.c recovery_instruc.c noleaks.c\
check_arg.c check_type.c which_arg.c trad.c trad_1.c ft_islabelchar.c\
common.c


OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libftprintf/ all
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L ../libftprintf/ -lftprintf

clean:
	make -C ../libftprintf/ clean
	rm -f $(OBJ)

fclean: clean
	make -C ../libftprintf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
