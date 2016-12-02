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

static int	get_arg_value(unsigned char *board, t_proc *c_proc, int *type,
	int arg_nb)
{
	if (type[arg_nb - 1] == REG)
		return (isreg(board, c_proc, type, arg_nb));
	else if (type[arg_nb - 1] == DIR)
		return ((short)isdir(board, c_proc, type, arg_nb));
	else if (type[arg_nb - 1] == IND)
		return (isind(board, c_proc, type, arg_nb));
	else
		return (0);
}

static int	valid_opc(unsigned char *board, t_proc *c_proc)
{
	int		cmp;

	cmp = (board[(c_proc->i + 1) % MEM_SIZE] & 0xfc);
	if (cmp == 0x64 || cmp == 0x54 || cmp == 0xa4 || cmp == 0x94 ||
		cmp == 0xe4 || cmp == 0xd4)
		return (1);
	return (0);
}

static void	is_valid_opc(t_cor *core, t_proc *c_proc, unsigned char *board,
	int cmd_size)
{
	int			arg_1;
	int			arg_2;
	int			*type;
	int			reg_nb;

	reg_nb = -1;
	type = get_type(board, c_proc);
	arg_1 = get_arg_value(board, c_proc, type, 1);
	arg_2 = get_arg_value(board, c_proc, type, 2);
	free(type);
	reg_nb = board[(c_proc->i + cmd_size - 1) % MEM_SIZE];
	if (reg_nb <= REG_NUMBER && reg_nb >= 1 && c_proc->error == 0)
	{
		c_proc->r[reg_nb - 1] = bit_cat(board, c_proc, (arg_1 + arg_2),
			REG_SIZE);
		if (core->options.verbose == 1)
		{
			ft_printf("P% 5d | lldi %d %d r%d\n", c_proc->pid, arg_1, arg_2,
			bit_cat(board, c_proc, cmd_size - 1, 1));
			ft_printf(
				"       | -> load from %d + %d = %d (with pc and mod %d)\n"
				, arg_1, arg_2, arg_1 + arg_2,
				(arg_1 + arg_2) + c_proc->i);
		}
	}
}

void		cmd_lldi(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int					cmd_size;

	if (c_proc->ctp == 50)
	{
		cmd_size = get_cmd_size(get_type(board, c_proc), 2, 3);
		if (valid_opc(board, c_proc) == 1)
			is_valid_opc(core, c_proc, board, cmd_size);
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
