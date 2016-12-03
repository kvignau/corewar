# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/12/02 02:59:44 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

FLAGS = -Wall -Werror -Wextra 

SRC = main.c
SRC += op.c
SRC += store_file.c
SRC += data_initializer.c
SRC += file_manager.c
SRC += ft_iscomment.c
SRC += recovery.c
SRC += header_manager.c
SRC += name_manager.c
SRC += comment_manager.c
SRC += error.c
SRC += free_all_data.c
SRC += recovery_instruc.c
SRC += noleaks.c
SRC += check_arg.c
SRC += check_type.c
SRC += which_arg.c
SRC += trad.c
SRC += trad_reg_ind.c
SRC += ft_islabelchar.c
SRC += common.c
SRC += label_manager.c
SRC += label.c
SRC += label_1.c
SRC += final_trad.c
SRC += create_file.c
SRC += data_initializer_1.c
SRC += recovery_label.c
SRC += define_arg.c
SRC += trad_dir.c
SRC += label_2.c
SRC += ft_hextoi.c
SRC += reverse_hexdump.c
SRC += add_f.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) ../libftprintf/libft.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
