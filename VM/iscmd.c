/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:14:25 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/15 18:14:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		iscmd(t_proc *c_proc, t_cor *core, t_dbllist *champ_list, t_dbllist *pr_list)
{
	c_proc->i = c_proc->i % MEM_SIZE;
	if (core->board[c_proc->i] == 1)
		cmd_live(core->board, c_proc, core, champ_list);
	else if (core->board[c_proc->i] == 2)
		cmd_ld(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 3)
		cmd_st(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 4)
		cmd_add(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 5)
		cmd_sub(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 6)
		cmd_and(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 7)
		cmd_or(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 8)
		cmd_xor(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 9)
		cmd_zjmp(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 10)
		cmd_ldi(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 11)
		cmd_sti(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 12)
		cmd_fork(core->board, c_proc, pr_list, core);
	else if (core->board[c_proc->i] == 13)
		cmd_lld(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 14)
		cmd_lldi(core->board, c_proc, core);
	else if (core->board[c_proc->i] == 15)
		cmd_lfork(core->board, c_proc, pr_list, core);
	else if (core->board[c_proc->i] == 16)
		cmd_aff(core->board, c_proc, core);
	else
		return (0);
	return (1);
}
