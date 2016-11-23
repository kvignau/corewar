/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:55:27 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/16 13:55:31 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					sti_result(unsigned char *board, t_proc *c_proc, int reg_nb, unsigned int add, t_cor *core)
{
	int					i;
	unsigned int		result;

	i = 0;
	result = 0;
	result = c_proc->r[reg_nb] >> (8 * (REG_SIZE - 1));
	while (i < REG_SIZE)
	{
		board[(c_proc->i + (add + i)) % MEM_SIZE] = result;
		core->color_map[(c_proc->i + (add + i)) % MEM_SIZE] = c_proc->color;
		result = c_proc->r[reg_nb] >> ((8 * (REG_SIZE - 1)) - (8 * (i + 1)));
		i++;
	}
}

int					add_ind_reg(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	int					reg_nb2;

	add = 0;
	reg_nb2 = 0;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 5) % MEM_SIZE] - 1;
	add = (c_proc->r[reg_nb2] + bit_cat(board, c_proc, 3, 2)) % IDX_MOD;
	if (v == 1)
		cmd_verbose_sti(board, c_proc, bit_cat(board, c_proc, 3, 2), c_proc->r[reg_nb2]);
	return (add);
}

int					add_reg_reg(unsigned char *board, t_proc *c_proc, int v, int *reg_nb)
{
	unsigned int		add;
	int					reg_nb2;
	int					reg_nb3;

	add = 0;
	reg_nb2 = 0;
	reg_nb3 = 0;
	*reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 3) % MEM_SIZE] - 1;
	reg_nb3 = board[(c_proc->i + 4) % MEM_SIZE] - 1;
	add = ((c_proc->r[reg_nb2] + c_proc->r[reg_nb3])) % IDX_MOD;
	if (v == 1)
		cmd_verbose_sti(board, c_proc, c_proc->r[reg_nb2], c_proc->r[reg_nb3]);
	return (add);
}