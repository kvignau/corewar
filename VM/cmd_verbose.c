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
	write(1, "ADV ", 4);
	ft_putnbr(offset);
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
	write(1, "P", 1);
	ft_printf("% 5d", c_proc->pid);
	write(1, " | sti r", 8);
	ft_putnbr(board[c_proc->i + 2]);
	write(1, " ", 1);
	ft_putnbr(p1);
	write(1, " ", 1);
	ft_putnbr(p2);
	write(1, "\n       | -> store to ", 22);
	ft_putnbr(p1);
	write(1, " + ", 3);
	ft_putnbr(p2);
	write(1, " = ", 3);
	ft_putnbr(p1 + p2);
	write(1, " (with pc and mod ", 18);
	ft_putnbr((((p1 + p2) % IDX_MOD) + c_proc->i) % MEM_SIZE);
	write(1, ")\n", 2);
}

void			cmd_verbose_st(int pid, int reg_nb, int id)
{
	write(1, "P", 1);
	ft_printf("% 5d", pid);
	write(1, " | st r", 7);
	ft_putnbr(reg_nb);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, "\n", 1);
}

void			cmd_verbose_ld(int pid, int reg_nb, int id)
{
	write(1, "P", 1);
	ft_printf("% 5d", pid);
	write(1, " | ld ", 6);
	ft_putnbr(reg_nb);
	write(1, " r", 2);
	ft_putnbr(id);
	write(1, "\n", 1);
}

void			cmd_verbose_zjmp_live(char *cmd, int pid, int id)
{
	write(1, "P", 1);
	ft_printf("% 5d", pid);
	write(1, " | ", 3);
	write(1, cmd, 4);
	write(1, " ", 1);
	ft_putnbr(id);
	// ft_printf("P% 5d | zjmp %d", c_proc->pid, (short int)id);
}