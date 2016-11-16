/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:37:32 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/10 14:37:34 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cmd_lld(unsigned char *board, t_proc *c_proc)
{
	unsigned int	id;
	int				reg_nb;

	if (c_proc->ctp == 5)
	{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x90)
		{
			id = bit_cat(board, c_proc, 2, 4);
			reg_nb = (int)((board[(c_proc->i + 6) % MEM_SIZE] - 1));
			if (reg_nb > 15 || reg_nb < 0)
				return ;
			c_proc->r[reg_nb] = id;
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0xd0)
		{
			id = bit_cat(board, c_proc, 2, 2);
			reg_nb = (int)((board[(c_proc->i + 4) % MEM_SIZE] - 1));
			if (reg_nb > 15 || reg_nb < 0)
				return ;
			if (id % MEM_SIZE == 1)
				c_proc->r[reg_nb] = (bit_cat(board, c_proc, id, 2) | 0xffff0000);
			else
				c_proc->r[reg_nb] = bit_cat(board, c_proc, id, 2);
		}
		if ((c_proc->i + id) % MEM_SIZE == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
		c_proc->ctp = 1;
		// if (opt_verbose == 1)
			cmd_verbose(board, c_proc, 4, 2);
		next_pc(get_cmd_size(get_type(board, c_proc), 4, 3), c_proc, board);
	}
	else
		c_proc->ctp += 1;
}
