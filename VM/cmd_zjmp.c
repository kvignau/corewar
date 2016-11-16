/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:23:27 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/10 11:23:29 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cmd_zjmp(unsigned char *board, t_proc *c_proc)
{
	unsigned int	id;

	if (c_proc->ctp == 20)
	{
		if (c_proc->carry == 1)
		{
			id = bit_cat(board, c_proc, 1, 2);
			c_proc->i = (c_proc->i + (id % IDX_MOD)) % IDX_MOD;
			c_proc->pc = &board[c_proc->i];
		}
		else
			next_pc(3, c_proc, board);
		c_proc->ctp = 0;
	}
	else
		c_proc->ctp += 1;
}
