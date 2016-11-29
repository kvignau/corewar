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

static int	dir_reg(t_cor *core, unsigned char *board, t_proc *c_proc)
{
	unsigned int	id;
	int				reg_nb;

	id = bit_cat(board, c_proc, 2, 4);
	reg_nb = (int)((board[(c_proc->i + 6) % MEM_SIZE] - 1));
	if (reg_nb < REG_NUMBER && reg_nb >= 0)
	{
		c_proc->r[reg_nb] = id;
		if (id == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
	}
	return(reg_nb);
}

static int	ind_reg(t_cor *core, unsigned char *board, t_proc *c_proc)
{
	unsigned int	id;
	int				reg_nb;

	id = bit_cat(board, c_proc, 2, 2);
	reg_nb = (int)((board[(c_proc->i + 4) % MEM_SIZE] - 1));
	if (reg_nb < REG_NUMBER && reg_nb >= 0)
	{
		c_proc->r[reg_nb] = bit_cat(board, c_proc, (id % IDX_MOD), 4);
		if (id == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
	}
	return(reg_nb);
}

void		cmd_ld(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int				*type;
	int				reg_nb;

	reg_nb = -1;
	if (c_proc->ctp == 5)
	{
		type = get_type(board, c_proc);
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x90)
			reg_nb = dir_reg(core, board, c_proc);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0xd0)
			reg_nb = ind_reg(core, board, c_proc);
		c_proc->ctp = 1;
		if (core->options.verbose == 1 &&
			((board[(c_proc->i + 1) % MEM_SIZE] == 0xd0) ||
			(board[(c_proc->i + 1) % MEM_SIZE] == 0x90)) &&
				(reg_nb < REG_NUMBER && reg_nb >= 0))
			cmd_verbose_ld(c_proc->pid, c_proc->r[reg_nb], reg_nb + 1);
		if (core->options.verbose == 1)
			cmd_verbose(board, c_proc, get_cmd_size(get_type(board, c_proc), 4, 2));
		c_proc->c_cmd = 0;
		next_pc(get_cmd_size(get_type(board, c_proc), 4, 2), c_proc, board);
	}
	else
		c_proc->ctp += 1;
}
