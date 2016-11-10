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

void	cmd_st(unsigned char *board, t_proc *c_proc)
{
	int				id;
	unsigned int	result;
	int				i;

	if (c_proc->ctp == 5)
	{
		i = 0;
		result = 0;
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x70)
		{
				id = bit_cat(board, c_proc, 3, 2);
				result = c_proc->r[(int)(board[(c_proc->i + 2) % MEM_SIZE]) - 1] >> 24;
				while (i < REG_SIZE)
				{
					board[(c_proc->i + ((id + i) % IDX_MOD)) % MEM_SIZE] = (unsigned char)result;
					result = c_proc->r[(int)(board[(c_proc->i + 2) % MEM_SIZE]) - 1] >> (24 - (8 * (i + 1)));
					i++;
				}
				next_pc(5, c_proc, board);
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x50)
		{
				c_proc->r[(int)(board[(c_proc->i + 3) % MEM_SIZE]) - 1] = c_proc->r[(int)(board[(c_proc->i + 2) % MEM_SIZE]) - 1];
				next_pc(4, c_proc, board);
		}
		c_proc->ctp = 0;
	}
	else
		c_proc->ctp += 1;
}