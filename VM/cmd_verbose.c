/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_verbose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:14:30 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/16 15:14:32 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cmd_verbose(unsigned char *board, t_proc *c_proc, int offset)
{
	int				i;

	i = 0;
	ft_printf("ADV %d", offset);
	ft_printf(" (0x%.4x -> 0x%.4x) ", c_proc->i, (c_proc->i + offset) % MEM_SIZE);
	while (i < offset)
	{
		ft_printf("%.2x ", board[(c_proc->i + i) % MEM_SIZE]);
		i++;
	}
	write(1, "\n", 1);
}

void			cmd_verbose_sti(unsigned char *board, t_proc *c_proc, int p1, int p2)
{
	ft_printf("P% 5d | sti r%d %d %d\n", c_proc->pid, board[c_proc->i + 2], p1, p2);
	ft_printf("% 6c | -> store to %d + %d = %d (with pc and mod %d)\n", ' ',p1, p2, p1 + p2, (((p1 + p2) % IDX_MOD) + c_proc->i) % MEM_SIZE);

}