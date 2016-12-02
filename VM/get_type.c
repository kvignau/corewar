/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:17:22 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/10 14:17:28 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_arg_type(char arg)
{
	if (arg == 0x1)
		return (REG);
	else if (arg == 0x2)
		return (DIR);
	else if (arg == 0x3)
		return (IND);
	return (0);
}

int				*get_type(unsigned char *board, t_proc *c_proc)
{
	char		arg1;
	char		arg2;
	char		arg3;
	int			*type;

	type = (int *)malloc(sizeof(int) * 3);
	arg1 = board[(c_proc->i + 1) % MEM_SIZE] >> 6 & 0x3;
	arg2 = board[(c_proc->i + 1) % MEM_SIZE] >> 4 & 0x3;
	arg3 = board[(c_proc->i + 1) % MEM_SIZE] >> 2 & 0x3;
	type[0] = get_arg_type(arg1);
	type[1] = get_arg_type(arg2);
	type[2] = get_arg_type(arg3);
	return (type);
}
