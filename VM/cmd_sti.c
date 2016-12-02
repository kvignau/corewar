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
	if ((*reg_nb < REG_NUMBER && *reg_nb >= 0) && (reg_nb2 < REG_NUMBER && reg_nb2 >= 0))
	{
		add = (c_proc->r[reg_nb2] + bit_cat(board, c_proc, id, 4)) % IDX_MOD;
		if (v == 1)
			cmd_verbose_sti(board, c_proc, bit_cat(board, c_proc, id, 4), c_proc->r[reg_nb2]);
		return (add);
	}
	c_proc->error = 1;
	return (-1);
}

static int				add_dir_ind(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	int					add;
	int					id;
	short				p2;

	add = 0;
	id = 0;
	p2 = bit_cat(board, c_proc, 5, 2);
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	id = bit_cat(board, c_proc, 3, 2);
	if (*reg_nb < REG_NUMBER && *reg_nb >= 0)
	{
		add = (p2 + bit_cat(board, c_proc, id, 4)) % IDX_MOD;
		if (v == 1)
			cmd_verbose_sti(board, c_proc, bit_cat(board, c_proc, id, 4), p2);
		return (add);
	}
	c_proc->error = 1;
	return (-1);
}

static int				add_ind_ind(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	short		p1;
	short		p2;

	add = 0;
	p1 = bit_cat(board, c_proc, 3, 2);
	p2 = bit_cat(board, c_proc, 5, 2);
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	if ((*reg_nb < REG_NUMBER && *reg_nb >= 0))
	{
		add = (p1 + p2) % IDX_MOD;
		if (v == 1)
			cmd_verbose_sti(board, c_proc, p1, p2);
		return (add);
	}
	c_proc->error = 1;
	return (-1);
}

static int				add_reg_ind(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	int					reg_nb2;

	add = 0;
	reg_nb2 = 0;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 3) % MEM_SIZE] - 1;
	if ((*reg_nb < REG_NUMBER && *reg_nb >= 0) && (reg_nb2 < REG_NUMBER && reg_nb2 >= 0))
	{
		add = (c_proc->r[reg_nb2] + bit_cat(board, c_proc, 4, 2)) % IDX_MOD;
		if (v == 1)
			cmd_verbose_sti(board, c_proc, c_proc->r[reg_nb2], bit_cat(board, c_proc, 4, 2));
		return (add);
	}
	c_proc->error = 1;
	return (-1);
}

void					cmd_sti(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int					reg_nb;
	int					cmd_size;
	int					add;
	int					cmp;

	reg_nb = 0;
	add = 0;
	cmd_size = 0;
	if (c_proc->ctp == 25)
	{
		cmp = (board[(c_proc->i + 1) % MEM_SIZE] & 0xfc);
		cmd_size = get_cmd_size(get_type(board, c_proc), 2, 3);
		if (cmp == 0x68)
			add = add_ind_ind(board, c_proc, core->options.verbose, &reg_nb);
		else if (cmp == 0x58)
			add = add_reg_ind(board, c_proc, core->options.verbose, &reg_nb);
		else if (cmp == 0x64)
			add = add_ind_reg(board, c_proc, core->options.verbose, &reg_nb);
		else if (cmp == 0x54)
			add = add_reg_reg(board, c_proc, core->options.verbose, &reg_nb);
		else if (cmp == 0x74)
			add = add_dir_reg(board, c_proc, core->options.verbose, &reg_nb);
		else if (cmp == 0x78)
			add = add_dir_ind(board, c_proc, core->options.verbose, &reg_nb);
		else
			cmp = -1;
		if (cmp != -1 && c_proc->error == 0)
			sti_result(core, c_proc, reg_nb, add);
		// if (core->cycles > 1970 && core->cycles < 2000)
		// {
		// 	ft_printf("oct : %x\n", board[(c_proc->i + 1) % MEM_SIZE]);
		// 	ft_printf("add : %d\n", add);
		// }
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
