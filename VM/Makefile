# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/10/10 14:47:30 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
#-fsanitize=address

FLAGS += -Wall -Wextra -Werror -fsanitize=address

SRC = main.c op.c corewar_usage.c options_checkers.c champions_maker.c

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
