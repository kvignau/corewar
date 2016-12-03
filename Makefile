# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 04:15:28 by kvignau           #+#    #+#              #
#    Updated: 2016/12/03 04:15:30 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_COR = corewar
NAME_ASM = asm
ASM = asm_files/
COR = VM/
PRINTF = libftprintf/

all: lib cor asm

lib:
	make -C $(PRINTF) all
cor:
	make -C $(COR) all
asm:
	make -C $(ASM) all
	
clean:
	@make -C $(PRINTF) clean
	make -C $(COR) clean
	make -C $(ASM) clean

fclean: clean
	@make -C $(PRINTF) fclean
	rm -f $(NAME_COR)
	rm -f $(NAME_ASM)

re: fclean all

.PHONY: re clean fclean all asm cor