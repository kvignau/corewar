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

void					cmd_lldi(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int					reg_nb;
	int					*type;
	int					arg_1;
	int					arg_2;
	int					v_opc;

	reg_nb = 0;
	v_opc = 0;
	if (c_proc->ctp == 50)
	{
		type = get_type(board, c_proc);
		if ((v_opc = valid_opc(board, c_proc)) == 1)
		{
			arg_1 = get_arg_value(board, c_proc, type, 1);
			arg_2 = get_arg_value(board, c_proc, type, 2);
			reg_nb = bit_cat(board, c_proc, get_cmd_size(type, 2, 3) - 1, 1);
			if (reg_nb <= REG_NUMBER && reg_nb >= 1)
			{
				c_proc->r[reg_nb - 1] = bit_cat(board, c_proc, (arg_1 + arg_2), REG_SIZE);
				if (core->options.verbose == 1)
				{
					ft_printf("P% 5d | lldi %d %d r%d\n", c_proc->pid, arg_1, arg_2, reg_nb);
					ft_printf("       | -> load from %u + %u = %d (with pc %d)\n",
						arg_1, arg_2, arg_1 + arg_2, (arg_1 + arg_2 + c_proc->i) % MEM_SIZE);
				}
			}
		}
		
		if (core->options.verbose == 1)
			cmd_verbose(board, c_proc, get_cmd_size(get_type(board, c_proc), 2, 3));
		c_proc->c_cmd = 0;
		next_pc(get_cmd_size(get_type(board, c_proc), 2, 3), c_proc, board);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
