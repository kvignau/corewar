/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:27:08 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/14 16:27:21 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int				add_dir_reg(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	unsigned int		id;
	int					reg_nb2;

	add = 0;
	id = 0;
	reg_nb2 = 0;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 5) % MEM_SIZE] - 1;
	id = bit_cat(board, c_proc, 3, 2);
	add = (c_proc->r[reg_nb2] + bit_cat(board, c_proc, id, 4)) % IDX_MOD;
	if (v == 1)
		cmd_verbose_sti(board, c_proc, bit_cat(board, c_proc, id, 4), c_proc->r[reg_nb2]);
	return (add);
}

static int				add_dir_ind(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	unsigned int		id;

	add = 0;
	id = 0;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	id = bit_cat(board, c_proc, 3, 2);
	add = (bit_cat(board, c_proc, 5, 2) + bit_cat(board, c_proc, id, 4)) % IDX_MOD;
	if (v == 1)
		cmd_verbose_sti(board, c_proc, bit_cat(board, c_proc, id, 4), bit_cat(board, c_proc, 5, 2));
	return (add);
}

static int				add_ind_ind(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;

	add = 0;
	add = (bit_cat(board, c_proc, 3, 2) + bit_cat(board, c_proc, 5, 2)) % IDX_MOD;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	if (v == 1)
		cmd_verbose_sti(board, c_proc, bit_cat(board, c_proc, 3, 2), bit_cat(board, c_proc, 5, 2));
	return (add);
}

static int				add_reg_ind(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	int					reg_nb2;

	add = 0;
	reg_nb2 = 0;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 3) % MEM_SIZE] - 1;
	add = (c_proc->r[reg_nb2] + bit_cat(board, c_proc, 4, 2)) % IDX_MOD;
	if (v == 1)
		cmd_verbose_sti(board, c_proc, c_proc->r[reg_nb2], bit_cat(board, c_proc, 4, 2));
	return (add);
}

static int				oct_codageok(unsigned char *board, t_proc *c_proc)
{
	if (board[(c_proc->i + 1) % MEM_SIZE] == 0x68 ||
		board[(c_proc->i + 1) % MEM_SIZE] == 0x58 ||
		board[(c_proc->i + 1) % MEM_SIZE] == 0x64 ||
		board[(c_proc->i + 1) % MEM_SIZE] == 0x54 ||
		board[(c_proc->i + 1) % MEM_SIZE] == 0x74 ||
		board[(c_proc->i + 1) % MEM_SIZE] == 0x78)
		return (1);
	return (0);
}

void					cmd_sti(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int					reg_nb;
	int					cmd_size;
	unsigned int		add;

	reg_nb = 0;
	add = 0;
	cmd_size = 0;
	if (c_proc->ctp == 25)
	{
		cmd_size = get_cmd_size(get_type(board, c_proc), 2, 3);
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x68)
			add = add_ind_ind(board, c_proc, core->options.verbose, &reg_nb);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x58)
			add = add_reg_ind(board, c_proc, core->options.verbose, &reg_nb);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x64)
			add = add_ind_reg(board, c_proc, core->options.verbose, &reg_nb);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x54)
			add = add_reg_reg(board, c_proc, core->options.verbose, &reg_nb);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x74)
			add = add_dir_reg(board, c_proc, core->options.verbose, &reg_nb);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x78)
			add = add_dir_ind(board, c_proc, core->options.verbose, &reg_nb);
		if (oct_codageok(board, c_proc))
			sti_result(board, c_proc, reg_nb, add);
		if (core->options.verbose == 1)
			cmd_verbose(board, c_proc, cmd_size);
		c_proc->c_cmd = 0;
		next_pc(cmd_size, c_proc, board);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
