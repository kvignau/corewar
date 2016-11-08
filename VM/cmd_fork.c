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

void		cmd_fork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list)
{
	unsigned int		value;
	t_elem				*tmp;

	if (c_proc->ctp == 800)
	{
		value = bit_cat(board, c_proc, 1, 2);
		ft_printf("value :%u\n", value);
		ft_lstdbladd_head(pr_list, (t_proc *)c_proc, sizeof(t_proc));
		tmp = pr_list->head;
		((t_proc *)(tmp->content))->pc = (c_proc->pc + (value % IDX_MOD));
		((t_proc *)(tmp->content))->i = (c_proc->i + (value % IDX_MOD));
		next_pc(3, c_proc, board);
		c_proc->ctp = 0;
	}
	else
		c_proc->ctp += 1;
}
