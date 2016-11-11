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
	int				reg_nb;

	// if (c_proc->ctp == 5)
	{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x90)
		{
			id = bit_cat(board, c_proc, 2, 4);
			reg_nb = (int)((board[(c_proc->i + 6) % MEM_SIZE] - 1));
			if (reg_nb > 15)
				return ;
			c_proc->r[reg_nb] = id;
			next_pc(7, c_proc, board);
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0xd0)
		{
			id = bit_cat(board, c_proc, 2, 2);
			reg_nb = (int)((board[(c_proc->i + 4) % MEM_SIZE] - 1));
			if (reg_nb > 15)
				return ;
			c_proc->r[reg_nb] = bit_cat(board, c_proc, (id % IDX_MOD), 4);
			next_pc(5, c_proc, board);
		}
		if ((c_proc->i + (id % IDX_MOD)) % MEM_SIZE == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
		c_proc->ctp = 0;
	}
	// else
		c_proc->ctp += 1;
}
