# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/05/24 11:30:02 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS += -Wall -Wextra -Werror

SRC = ft_ls.c lst_act.c display.c file_info.c read_file.c lstdir.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/ all
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L ft_printf/ -lftprintf

clean:
	make -C ft_printf/ clean
	rm -f $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
