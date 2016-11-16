/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cmd_add(unsigned char *board, t_proc *c_proc)
{
	int		r1;
	int		r2;
	int		r_dest;

	r1 = 0;
	r2 = 0;
	r_dest = 0;
	if (c_proc->ctp == 10)
	{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x54)
		{
			r1 = board[(c_proc->i + 2) % MEM_SIZE];
			r2 = board[(c_proc->i + 3) % MEM_SIZE];
			r_dest = board[(c_proc->i + 4) % MEM_SIZE];
			if (r1 <= REG_NUMBER && r2 <= REG_NUMBER
				&& r_dest <= REG_NUMBER && r1 > 0 && r2 > 0 && r_dest > 0)
			{
				c_proc->r[r_dest - 1] = c_proc->r[r1 - 1] + c_proc->r[r2 - 1];
				c_proc->carry = c_proc->r[r_dest - 1] == 0 ? 1 : 0;
			}
		}
		// if (opt_verbose == 1)
			cmd_verbose(board, c_proc, 4, 2);
		next_pc(get_cmd_size(get_type(board, c_proc), 4, 3), c_proc, board);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
