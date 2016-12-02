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
	int				j;
	char			*hex1;
	char			*hex2;
	char			*hex3;

	i = 0;
	write(1, "ADV ", 4);
	ft_putnbr(offset);
	write(1, " (0x", 4);
	hex1 = ft_strtolower(ft_itoabase_imax(c_proc->i, 16));
	hex2 = ft_strtolower(ft_itoabase_imax(c_proc->i + offset, 16));
	while (i + ft_strlen(hex1) < 4)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putstr(hex1);
	free(hex1);
	i = 0;
	write(1, " -> 0x", 6);
	while (i + ft_strlen(hex2) < 4)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putstr(hex2);
	free(hex2);
	write(1, ") ", 2);
	i = 0;
	while (i < offset)
	{
		hex3 = ft_strtolower(ft_itoabase_imax(board[(c_proc->i + i) % MEM_SIZE],
		16));
		j = 0;
		while (j + ft_strlen(hex3) < 2)
		{
			write(1, "0", 1);
			j++;
		}
		ft_putstr(hex3);
		free(hex3);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void			cmd_verbose_sti(unsigned char *board, t_proc *c_proc, int p1,
	int p2)
{
	write(1, "P", 1);
	ft_printf("% 5d", c_proc->pid);
	write(1, " | sti r", 8);
	ft_putnbr(board[(c_proc->i + 2) % MEM_SIZE]);
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
	ft_putnbr(((p1 + p2) % IDX_MOD + c_proc->i));
	write(1, ")\n", 2);
}

void			cmd_verbose_st(int pid, int reg_nb, int id)
{
	write(1, "P", 1);
	if (pid < 10)
		write(1, " ", 1);
	if (pid < 100)
		write(1, " ", 1);
	if (pid < 1000)
		write(1, " ", 1);
	if (pid < 100000)
		write(1, " ", 1);
	ft_putnbr(pid);
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
	if (pid < 10)
		write(1, " ", 1);
	if (pid < 100)
		write(1, " ", 1);
	if (pid < 1000)
		write(1, " ", 1);
	if (pid < 100000)
		write(1, " ", 1);
	ft_putnbr(pid);
	write(1, " | ", 3);
	write(1, cmd, 4);
	write(1, " ", 1);
	ft_putnbr(id);
}
