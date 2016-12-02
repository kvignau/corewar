/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:04:00 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/08 16:04:07 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	next_pc(int counter_offset, t_proc *c_proc, unsigned char *board)
{
	c_proc->pc = &board[(c_proc->i + counter_offset) % MEM_SIZE];
	c_proc->i += counter_offset;
}
