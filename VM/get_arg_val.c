/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_arg_val(int oc_trunc, unsigned char *board, t_proc *c_proc,
	int i[])
{
	int		arg;

	arg = 0;
	if (oc_trunc == 0b10)
	{
		arg = bit_cat(board, c_proc, i[0], 4);
		i[0] += 4;
		return (arg);
	}
	else if (oc_trunc == 0b11)
	{
		arg = bit_cat(board, c_proc, i[0], 2);
		arg = bit_cat(board, c_proc, (arg % IDX_MOD), 4);
		i[0] += 2;
		return (arg);
	}
	else if (oc_trunc == 0b01)
	{
		arg = get_register_name(board, c_proc, i);
		if (i[1] == 0)
			arg = c_proc->r[arg - 1];
		return (arg);
	}
	else
		i[1] = -1;
	return (0);
}
