/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:42:37 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/09 13:42:48 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_arg_value(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
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

void					cmd_ldi(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int					reg_nb;
	int					*type;
	short				arg_1;
	short				arg_2;
	int					v_opc;
	int					cmd_size;

	reg_nb = 0;
	v_opc = 0;
	if (c_proc->ctp == 25)
	{
		cmd_size = get_cmd_size(get_type(board, c_proc), 2, 3);
		if ((v_opc = valid_opc(board, c_proc)) == 1)
		{
			type = get_type(board, c_proc);
			arg_1 = get_arg_value(board, c_proc, type, 1);
			arg_2 = get_arg_value(board, c_proc, type, 2);
			free(type);
			reg_nb = bit_cat(board, c_proc, get_cmd_size(get_type(board, c_proc), 2, 3) - 1, 1);
			if (reg_nb <= REG_NUMBER && reg_nb >= 1 && c_proc->error == 0)
			{
				c_proc->r[reg_nb - 1] = bit_cat(board, c_proc, (arg_1 + arg_2) % IDX_MOD, REG_SIZE);
				if (core->options.verbose == 1)
				{
					ft_printf("P% 5d | ldi %d %d r%d\n", c_proc->pid, arg_1, arg_2, reg_nb);
					ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
						arg_1, arg_2, arg_1 + arg_2, (arg_1 + arg_2) % IDX_MOD + c_proc->i);
				}
			}
		}
		if (core->options.verbose == 1)
			cmd_verbose(board, c_proc, cmd_size);
		c_proc->c_cmd = 0;
		next_pc(cmd_size, c_proc, board);
		c_proc->ctp = 1;
		c_proc->error = 0;
	}
	else
		c_proc->ctp += 1;
}