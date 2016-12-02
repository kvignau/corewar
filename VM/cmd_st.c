/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:08:45 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/09 15:08:48 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		result_st(t_cor *core, t_proc *c_proc, int reg_nb, short int id)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = c_proc->r[reg_nb] >> 24;
	while (i < REG_SIZE)
	{
		core->board[(c_proc->i + ((unsigned int)(id % IDX_MOD) +
			i)) % MEM_SIZE] = result;
		core->color_map[(c_proc->i + ((unsigned int)(id % IDX_MOD) +
			i)) % MEM_SIZE] = c_proc->color;
		result = c_proc->r[reg_nb] >> (24 - (8 * (i + 1)));
		i++;
	}
}

static void		reg_ind(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	short int		id;
	int				reg_nb;

	id = bit_cat(board, c_proc, 3, 2);
	reg_nb = (int)((board[(c_proc->i + 2) % MEM_SIZE] - 1));
	if (reg_nb < REG_NUMBER && reg_nb >= 0)
	{
		if (core->options.verbose == 1)
			cmd_verbose_st(c_proc->pid, reg_nb + 1, id);
		result_st(core, c_proc, reg_nb, id);
	}
}

static void		reg_reg(unsigned char *board, t_proc *c_proc, int verbose)
{
	int				reg_nb;
	int				reg_nb2;

	reg_nb = (int)(board[(c_proc->i + 3) % MEM_SIZE]) - 1;
	reg_nb2 = (int)(board[(c_proc->i + 2) % MEM_SIZE]) - 1;
	if ((reg_nb < REG_NUMBER && reg_nb >= 0) &&
		(reg_nb2 < REG_NUMBER && reg_nb2 >= 0))
	{
		if (verbose == 1)
			cmd_verbose_st(c_proc->pid, reg_nb2 + 1, reg_nb + 1);
		c_proc->r[reg_nb] = c_proc->r[reg_nb2];
	}
}

void			cmd_st(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int				cmd_size;
	int				cmp;

	if (c_proc->ctp == 5)
	{
		cmp = (board[(c_proc->i + 1) % MEM_SIZE] & 0xf0);
		cmd_size = get_cmd_size(get_type(board, c_proc), 4, 2);
		if (cmp == 0x70)
			reg_ind(board, c_proc, core);
		else if (cmp == 0x50)
			reg_reg(board, c_proc, core->options.verbose);
		c_proc->c_cmd = 0;
		next(board, c_proc, cmd_size, core->options.verbose);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
