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

static void		next(unsigned char *board, t_proc *c_proc, int nb, int verbose)
{
	if (verbose == 1)
		cmd_verbose(board, c_proc, nb);
	next_pc(nb, c_proc, board);
}

void	cmd_st(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	short int		id;
	unsigned char	result;
	int				i;
	int				reg_nb;
	int				reg_nb2;

	if (c_proc->ctp == 5)
	{
		i = 0;
		result = 0;
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x70)
		{
			id = (short int)bit_cat(board, c_proc, 3, 2);
			reg_nb = (int)((board[(c_proc->i + 2) % MEM_SIZE] - 1));
			if (reg_nb > 15 || reg_nb < 0)
			{
				next(board, c_proc, get_cmd_size(get_type(board, c_proc), 4, 2), core->options.verbose);
				return ;
			}
			if (core->options.verbose == 1)
				ft_printf("P% 5d | st r%d %d\n", c_proc->pid, reg_nb + 1, (short int)id);
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x50)
		{
			reg_nb = (int)(board[(c_proc->i + 3) % MEM_SIZE]) - 1;
			reg_nb2 = (int)(board[(c_proc->i + 2) % MEM_SIZE]) - 1;
			if (reg_nb > 15 || reg_nb < 0 || reg_nb2 > 15 || reg_nb2 < 0)
			{
				next(board, c_proc, get_cmd_size(get_type(board, c_proc), 4, 2), core->options.verbose);
				return ;
			}
			if (core->options.verbose == 1)
				ft_printf("P% 5d | st r%d %d\n", c_proc->pid, reg_nb2 + 1,
					reg_nb + 1);
			c_proc->r[reg_nb] = c_proc->r[reg_nb2];
		}
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x70)
		{
			reg_nb2 = get_cmd_size(get_type(board, c_proc), 4, 2);
			result = c_proc->r[reg_nb] >> 24;
			while (i < REG_SIZE)
			{
				board[(c_proc->i + ((id + i) % IDX_MOD)) % MEM_SIZE] = result;
				result = c_proc->r[reg_nb] >> (24 - (8 * (i + 1)));
				i++;
			}
			next(board, c_proc, reg_nb2, core->options.verbose);
		}
		else
			next(board, c_proc, get_cmd_size(get_type(board, c_proc), 4, 2), core->options.verbose);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}