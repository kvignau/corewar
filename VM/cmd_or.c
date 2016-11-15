/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cmd_or(unsigned char *board, t_proc *c_proc)
{
	int		o_code;
	int		arg1;
	int		arg2;
	int		r_dest;
	int		i[2];

	i[0] = 2;
	i[1] = 0;
	o_code = board[(c_proc->i + 1) % MEM_SIZE];
	// if (c_proc->ctp == 6)
	// {
		arg1 = get_arg_val((o_code & 0b11000000) >> 6, board, c_proc, i);
		arg2 = get_arg_val((o_code & 0b00110000) >> 4, board, c_proc, i);
		r_dest = get_register_name(board, c_proc, i);
		if (i[1] == 0)
		{
			c_proc->r[r_dest - 1] = arg1 | arg2;
			c_proc->carry = c_proc->r[r_dest - 1] == 0 ? 0 : 1;
		}
		next_pc(get_cmd_size(get_type(board, c_proc), 4, 3), c_proc, board);
		c_proc->ctp = 0;
	// }
	// else
	// 	c_proc->ctp += 1;
}
