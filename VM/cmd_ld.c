/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:08:17 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/08 16:08:19 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cmd_ld(unsigned char *board, t_proc *c_proc)
{
	unsigned int	id;

	// if (board[(c_proc->i + 1) % MEM_SIZE] == 0x90)
	// {
			// id = bit_cat(board, c_proc, 2, 4);
			// c_proc->r[(int)(board[(c_proc->i + (start + i)) % MEM_SIZE]) - 1] = c_proc->pc + (id % IDX_MOD);
	// }
	// if (board[(c_proc->i + 1) % MEM_SIZE] == 0xd0)
	// {
	// 	return ;
	// }
	//next_pc(3, c_proc);
}

unsigned int		bit_cat(unsigned char *board, t_proc *c_proc, int start, int size)
{
	unsigned int	result;
	unsigned int	nb;
	int				i;

	i = 0;
	while (i < size)
	{
		nb = board[(c_proc->i + (start + i)) % MEM_SIZE];
		result = result | nb;
		if (i < size - 1)
			result = result << 8;
		i++;
	}
	return (result);
}