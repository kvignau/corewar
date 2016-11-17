/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 13:55:32 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 11:31:02 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cmd_aff(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	if (c_proc->ctp == 2)
	{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x40)
			write(1, (int *)&board[(c_proc->i + 2) % MEM_SIZE], 1);
		if (core->options.verbose == 1)
			cmd_verbose(board, c_proc, get_cmd_size(get_type(board, c_proc), 4, 1));
		next_pc(get_cmd_size(get_type(board, c_proc), 4, 1), c_proc, board);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}