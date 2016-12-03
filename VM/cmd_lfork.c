/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		norm_lfork(t_elem *tmp, t_proc *c_proc, short int value,
	unsigned char *board)
{
	((t_proc *)(tmp->content))->i = ((c_proc->i + (value)) % MEM_SIZE);
	((t_proc *)(tmp->content))->pc = &(board[((t_proc *)(tmp->content))->i]);
	((t_proc *)(tmp->content))->ctp = 1;
	((t_proc *)(tmp->content))->c_cmd = 0;
	((t_proc *)(tmp->content))->color = c_proc->color;
}

void		cmd_lfork(unsigned char *board, t_proc *c_proc,
	t_dbllist *pr_list, t_cor *core)
{
	short int		value;
	t_elem			*tmp;

	if (c_proc->ctp == 1000)
	{
		value = bit_cat(board, c_proc, 1, 2);
		ft_lstdbladd_head(pr_list, (t_proc *)c_proc, sizeof(t_proc));
		tmp = pr_list->head;
		if (core->options.verbose == 1)
		{
			ft_printf("P% 5d | lfork %d (%d)\n", c_proc->pid, value,
				(c_proc->i + value));
			cmd_verbose(board, c_proc, 3);
		}
		norm_lfork(tmp, c_proc, value, board);
		core->pid += 1;
		((t_proc *)(tmp->content))->pid = core->pid;
		c_proc->c_cmd = 0;
		next_pc(3, c_proc, board);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
