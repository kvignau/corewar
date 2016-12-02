/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 03:37:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/12/02 03:37:14 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		verbose_cycles(t_cor *core)
{
	write(1, "It is now cycle ", 16);
	ft_putnbr(core->cycles);
	write(1, "\n", 1);
}

void		cmd_verbose_zjmp_live(char *cmd, int pid, int id)
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
	if (pid >= 100000)
		write(1, " ", 1);
	ft_putnbr(pid);
	write(1, " | ", 3);
	write(1, cmd, 4);
	write(1, " ", 1);
	ft_putnbr(id);
}
