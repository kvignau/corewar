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

void	cmd_aff(unsigned char *b, t_proc *c_proc, t_cor *core)
{
	int		reg_nb;

	reg_nb = -1;
	if (c_proc->ctp == 2)
	{
		if ((b[(c_proc->i + 1) % MEM_SIZE] & 0xc0) == 0x40)
		{
			reg_nb = (int)((b[(c_proc->i + 2) % MEM_SIZE] - 1));
			if (reg_nb <= 15 && reg_nb >= 0)
			{
				if (core->options.aff == 0)
				{
					write(1, &c_proc->r[reg_nb], 1);
					write(1, "\n", 1);
				}
			}
		}
		if (core->options.verbose == 1)
			cmd_verbose(b, c_proc, get_cmd_size(get_type(b, c_proc), 4, 1));
		c_proc->c_cmd = 0;
		next_pc(get_cmd_size(get_type(b, c_proc), 4, 1), c_proc, b);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}
