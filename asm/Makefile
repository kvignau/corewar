# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/12/01 20:04:02 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Werror -Wextra

SRC = main.c op.c store_file.c data_initializer.c file_manager.c \
ft_iscomment.c recovery.c header_manager.c name_manager.c \
comment_manager.c error.c free_all_data.c recovery_instruc.c noleaks.c \
check_arg.c check_type.c which_arg.c trad.c trad_reg_ind.c ft_islabelchar.c \
common.c label_manager.c label.c label_1.c final_trad.c create_file.c \
data_initializer_1.c recovery_label.c define_arg.c trad_dir.c label_2.c \
ft_hextoi.c reverse_hexdump.c add_f.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ -L../libftprintf/ -lftprintf

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -Iincludes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
