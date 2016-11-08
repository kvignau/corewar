# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/10/19 16:20:18 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
#-fsanitize=address

FLAGS += -Wall -Wextra -Werror -fsanitize=address

SRC = main.c op.c corewar_usage.c options_checkers.c champions_maker.c \
ft_print_memory.c memory.c ft_hextoa.c get_content.c ft_hextoi.c\
init_board.c intro.c cmd_aff.c cmd_fork.c next_pc.c

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
