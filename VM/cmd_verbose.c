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
	ft_printf(" (0x%.4x -> 0x%.4x) ", c_proc->i, c_proc->i + offset);
	while (i < offset)
	{
		ft_printf("%.2x ", board[c_proc->i + i]);
		i++;
	}
	write(1, "\n", 1);
}