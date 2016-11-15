/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:22:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/10 19:23:13 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned int		get_arg_value(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	if (type[arg_nb - 1] == REG)
		return(isreg(board, c_proc, type, arg_nb));
	else if (type[arg_nb - 1] == DIR)
		return (isdir(board, c_proc, type, arg_nb));
	else if (type[arg_nb - 1] == IND)
		return (isind(board, c_proc, type, arg_nb));
	else
		return (0);
}

static int				valid_opc(unsigned char *board, t_proc *c_proc)
{
	int		cmp;

	cmp = board[(c_proc->i + 1) % MEM_SIZE];
	if (cmp == 0x64 || cmp == 0x54 || cmp == 0xa4 || cmp == 0x94 ||
		cmp == 0xe4 || cmp == 0xd4)
		return (1);
	return (0);
}

void					cmd_lldi(unsigned char *board, t_proc *c_proc)
{
	unsigned int		result;
	int					reg_nb;
	int					*type;
	int					first_arg;


	result = 0;
	reg_nb = 0;
	// if (c_proc->ctp == 25)
	{
		type = get_type(board, c_proc);
		if (valid_opc(board, c_proc) == 1)
		{
			result = get_arg_value(board, c_proc, type, 1) + get_arg_value(board, c_proc, type, 2);
			reg_nb = bit_cat(board, c_proc, get_cmd_size(type, 2, 3) - 1, 1);
			if (reg_nb > 15 || reg_nb < 0)
				return ;
			c_proc->r[reg_nb - 1] = bit_cat(board, c_proc, (result) % MEM_SIZE, REG_SIZE);
		}
		if (c_proc->r[reg_nb - 1] == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
		next_pc(get_cmd_size(type, 2, 3), c_proc, board);
		c_proc->ctp = 0;
	}
	// else
		c_proc->ctp += 1;
}