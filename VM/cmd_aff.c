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

void	cmd_aff(unsigned char *board, t_proc *c_proc)
{
	if (board[(c_proc->i + 1) % MEM_SIZE] == 0x40)
		write(1, (int *)&board[(c_proc->i + 2) % MEM_SIZE], 1);
	c_proc->pc = &board[(c_proc->i + 3) % MEM_SIZE];
	c_proc->i += 3;
}