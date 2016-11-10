/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_register_name(unsigned char *board, t_proc *c_proc, int i[])
{
	int		r_dest;

	r_dest = bit_cat(board, c_proc, i[0], 1);
	i[0] += 1;
	if (r_dest <= 0 || r_dest > REG_NUMBER)
	{
		i[1] = -1;
	}
	return (r_dest);
}

int			get_arg_val(int oc_trunc, unsigned char *board, t_proc *c_proc, int i[])
{
	int		arg;

	arg = 0;
	if (oc_trunc == 0b10)
	{
		arg = bit_cat(board, c_proc, i[0], 4);
		i[0] += 4;
		return (arg);
	}
	else if (oc_trunc == 0b11)
	{
		arg = bit_cat(board, c_proc, i[0], 2);
		arg = bit_cat(board, c_proc, arg, 4);
		i[0] += 2;
		return (arg);
	}
	if (oc_trunc == 0b01)
	{
		arg = get_register_name(board, c_proc, i);
		if (i[1] == 0)
			arg = c_proc->r[arg - 1];
		return (arg);
	}
	return (0);
}

void		cmd_xor(unsigned char *board, t_proc *c_proc)
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
		if (i[1] == -1){
			next_pc(i[0], c_proc, board);
			c_proc->ctp = 0;
			return ;
		}
		c_proc->r[r_dest - 1] = arg1 | arg2;
		c_proc->carry = c_proc->r[r_dest - 1] == 0 ? 0 : 1;
		next_pc(i[0], c_proc, board);
		c_proc->ctp = 0;
	// }
	// else
	// 	c_proc->ctp += 1;
}
