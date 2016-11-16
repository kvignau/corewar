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

static void				add_dir_reg(unsigned char *board, t_proc *c_proc)
{
	unsigned int		add;
	unsigned int		id;
	int					reg_nb;
	int					reg_nb2;

	add = 0;
	id = 0;
	reg_nb = 0;
	reg_nb2 = 0;
	reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 5) % MEM_SIZE] - 1;
	id = bit_cat(board, c_proc, 3, 2);
	add = (c_proc->r[reg_nb2] + bit_cat(board, c_proc, id + 2, 2)) % IDX_MOD;
	sti_result(board, c_proc, reg_nb, add);
}

static void				add_dir_ind(unsigned char *board, t_proc *c_proc)
{
	unsigned int		add;
	unsigned int		id;
	int					reg_nb;

	add = 0;
	id = 0;
	reg_nb = 0;
	reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	id = bit_cat(board, c_proc, 3, 2);
	add = (bit_cat(board, c_proc, 5, 2) + bit_cat(board, c_proc, id + 2, 2)) % IDX_MOD;
	sti_result(board, c_proc, reg_nb, add);
}

static void				add_ind_ind(unsigned char *board, t_proc *c_proc)
{
	unsigned int		add;
	int					reg_nb;

	add = 0;
	reg_nb = 0;
	add = bit_cat(board, c_proc, 3, 2) + bit_cat(board, c_proc, 5, 2);
	reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	sti_result(board, c_proc, reg_nb, add);
}

static void				add_reg_ind(unsigned char *board, t_proc *c_proc)
{
	unsigned int		add;
	int					reg_nb;
	int					reg_nb2;

	add = 0;
	reg_nb = 0;
	reg_nb2 = 0;
	reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;
	reg_nb2 = board[(c_proc->i + 3) % MEM_SIZE] - 1;
	add = c_proc->r[reg_nb2] + bit_cat(board, c_proc, 4, 2);
	sti_result(board, c_proc, reg_nb, add);
}

void					cmd_sti(unsigned char *board, t_proc *c_proc)
{
	// if (c_proc->ctp == 25)
	{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x68)
			add_ind_ind(board, c_proc);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x58)
			add_reg_ind(board, c_proc);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x64)
			add_ind_reg(board, c_proc);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x54)
			add_reg_reg(board, c_proc);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x74)
			add_dir_reg(board, c_proc);
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x78)
			add_dir_ind(board, c_proc);
		ft_printf("ADV %d\n", get_cmd_size(get_type(board, c_proc), 2, 3));
		next_pc(get_cmd_size(get_type(board, c_proc), 2, 3), c_proc, board);
		c_proc->ctp = 1;
	}
	// else
		c_proc->ctp += 1;
}
