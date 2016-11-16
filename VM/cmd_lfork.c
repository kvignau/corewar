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

void		cmd_lfork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list)
{
	int		value;
	t_elem				*tmp;

	if (c_proc->ctp == 1000)
	{
		value = bit_cat(board, c_proc, 1, 2);
		ft_lstdbladd_head(pr_list, (t_proc *)c_proc, sizeof(t_proc));
		tmp = pr_list->head;
		// if (opt_verbose == 1)
			cmd_verbose(board, c_proc, 3);
		next_pc(3, c_proc, board);
		((t_proc *)(tmp->content))->pc = (c_proc->pc + (value));
		((t_proc *)(tmp->content))->i = (c_proc->i + (value));
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
