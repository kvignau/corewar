/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:08:17 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/08 16:08:19 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cmd_ld(unsigned char *board, t_proc *c_proc)
{
	unsigned int	id;

	if (c_proc->ctp == 5)
	{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x90)
		{
				id = bit_cat(board, c_proc, 2, 4);
				c_proc->r[(int)(board[c_proc->i + 6 % MEM_SIZE]) - 1] = (int)(c_proc->pc + (id % IDX_MOD));
				// ft_printf("indirect %d\n", c_proc->pc);
				// ft_printf("TEST DE OUF indirect %x\n", c_proc->pc + (id % IDX_MOD));
				next_pc(7, c_proc, board);
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0xd0)
		{
				id = bit_cat(board, c_proc, 2, 2);
				c_proc->r[(int)(board[c_proc->i + 4 % MEM_SIZE] - 1)] = (int)(c_proc->pc + (id % IDX_MOD));
				// ft_printf("direct %d\n", c_proc->pc);
				// ft_printf("TEST DE OUF direct %x\n", c_proc->pc + (id % IDX_MOD));
				next_pc(5, c_proc, board);
		}
		//ajout modif carry
		c_proc->ctp += 1;
	}
	else
		c_proc->ctp += 1;
}

unsigned int		bit_cat(unsigned char *board, t_proc *c_proc, int start, int size)
{
	unsigned int	result;
	unsigned int	nb;
	int				i;

	i = 0;
	nb = 0;
	result = 0;
	while (i < size)
	{
		nb = board[(c_proc->i + (start + i)) % MEM_SIZE];
		result = result | nb;
		if (i < size - 1)
			result = result << 8;
		i++;
	}
	return (result);
}