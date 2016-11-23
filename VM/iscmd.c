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
	if (c_proc->c_cmd == 0)
		c_proc->c_cmd = core->board[c_proc->i];
	if (c_proc->c_cmd == 1)
		cmd_live(core->board, c_proc, core, champ_list);
	else if (c_proc->c_cmd == 2)
		cmd_ld(core->board, c_proc, core);
	else if (c_proc->c_cmd == 3)
		cmd_st(core->board, c_proc, core);
	else if (c_proc->c_cmd == 4)
		cmd_add(core->board, c_proc, core);
	else if (c_proc->c_cmd == 5)
		cmd_sub(core->board, c_proc, core);
	else if (c_proc->c_cmd == 6)
		cmd_and(core->board, c_proc, core);
	else if (c_proc->c_cmd == 7)
		cmd_or(core->board, c_proc, core);
	else if (c_proc->c_cmd == 8)
		cmd_xor(core->board, c_proc, core);
	else if (c_proc->c_cmd == 9)
		cmd_zjmp(core->board, c_proc, core);
	else if (c_proc->c_cmd == 10)
		cmd_ldi(core->board, c_proc, core);
	else if (c_proc->c_cmd == 11)
		cmd_sti(core->board, c_proc, core);
	else if (c_proc->c_cmd == 12)
		cmd_fork(core->board, c_proc, pr_list, core);
	else if (c_proc->c_cmd == 13)
		cmd_lld(core->board, c_proc, core);
	else if (c_proc->c_cmd == 14)
		cmd_lldi(core->board, c_proc, core);
	else if (c_proc->c_cmd == 15)
		cmd_lfork(core->board, c_proc, pr_list, core);
	else if (c_proc->c_cmd == 16)
		cmd_aff(core->board, c_proc, core);
	else
		return (0);
	return (1);
}
