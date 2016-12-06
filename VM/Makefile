# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/12/06 14:58:02 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

FLAGS = -Wall -Werror -Wextra

SRC = main.c
SRC += corewar_usage.c
SRC += options_checkers.c
SRC += champions_maker.c
SRC += ft_print_memory.c
SRC += memory.c
SRC += ft_hextoa.c
SRC += get_content.c
SRC += ft_hextoi.c
SRC += init_board.c
SRC += intro.c
SRC += cmd_aff.c
SRC += cmd_fork.c
SRC += next_pc.c
SRC += cmd_ld.c
SRC += cmd_lfork.c
SRC += bit_cat.c
SRC += cmd_ldi.c
SRC += cmd_st.c
SRC += cmd_add.c
SRC += cmd_sub.c
SRC += cmd_zjmp.c
SRC += get_type.c
SRC += cmd_lld.c
SRC += get_cmd_size.c
SRC += cmd_lldi.c
SRC += cmd_and.c
SRC += cmd_or.c
SRC += cmd_xor.c
SRC += get_arg_val.c
SRC += get_register_name.c
SRC += isdir.c
SRC += isind.c
SRC += isreg.c
SRC += cmd_sti.c
SRC += cmd_live.c
SRC += iscmd.c
SRC += execute_dead_process.c
SRC += opt_sti.c
SRC += cmd_verbose.c
SRC += ncurs_set_up.c
SRC += ncurs_finish.c
SRC += ncurs_print_board.c
SRC += next.c
SRC += verbose2.c
SRC += game_loop.c
SRC += error_manager.c
SRC += reverse_byte.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) ../libftprintf/libft.a -lncurses

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -Iincludes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
