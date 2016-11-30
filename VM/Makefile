# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/11/22 17:49:40 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
#-fsanitize=address

FLAGS = -g -Wall -Wextra -fsanitize=address 
# -Werror

# MallocStackLogging=1

SRC = main.c op.c corewar_usage.c options_checkers.c champions_maker.c \
ft_print_memory.c memory.c ft_hextoa.c get_content.c ft_hextoi.c\
init_board.c intro.c cmd_aff.c cmd_fork.c next_pc.c cmd_ld.c cmd_lfork.c\
bit_cat.c cmd_ldi.c cmd_st.c cmd_add.c cmd_sub.c cmd_zjmp.c get_type.c\
cmd_lld.c get_cmd_size.c cmd_lldi.c cmd_and.c cmd_or.c cmd_xor.c\
get_arg_val.c get_register_name.c isdir.c isind.c isreg.c cmd_sti.c\
cmd_live.c iscmd.c execute_dead_process.c opt_sti.c cmd_verbose.c\
ncurs_set_up.c ncurs_finish.c ncurs_print_board.c next.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

# $(NAME): $(OBJ)
# 	make -C ../libftprintf/ all
# 	$(CC) $(FLAGS) -o $(NAME) $(OBJ) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ -L../libftprintf/ -lftprintf -lncurses

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -Iincludes

clean:
	# make -C ../libftprintf/ clean
	rm -f $(OBJ)

fclean: clean
	# make -C ../libftprintf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
