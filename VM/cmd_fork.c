/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cmd_fork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list, t_cor *core)
{
	int					value;
	t_elem				*tmp;

	if (c_proc->ctp == 800)
	{
		value = bit_cat(board, c_proc, 1, 2);
		ft_lstdbladd_head(pr_list, (t_proc *)c_proc, sizeof(t_proc));
		tmp = pr_list->head;
		if (core->options.verbose == 1)
			cmd_verbose(board, c_proc, 3);
		((t_proc *)(tmp->content))->pc = (c_proc->pc + (value % IDX_MOD));
		// ft_printf("prei : %d\n", ((t_proc *)(tmp->content))->i);
		((t_proc *)(tmp->content))->i = (c_proc->i + (value % IDX_MOD));
		// ft_printf("posti : %d\n", ((t_proc *)(tmp->content))->i);
		((t_proc *)(tmp->content))->ctp = 1;
		((t_proc *)(tmp->content))->live = 0;
		// core->pid += 1;
		// proc->pid = core->pid;
		next_pc(3, c_proc, board);
		// ft_printf("fork->i : %.4x\nfork->pc: %p\n",((t_proc *)(tmp->content))->i, ((t_proc *)(tmp->content))->pc);
		// ft_printf("notfork->i : %d\nnotfork->pc: %p\n",c_proc->i, c_proc->pc);


		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
