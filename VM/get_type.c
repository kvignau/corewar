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

static int		get_arg_type(char *arg)
{
	if (ft_strcmp((char *)arg, "01") == 0)
		return (REG);
	if (ft_strcmp((char *)arg, "10") == 0)
		return (DIR);
	if (ft_strcmp((char *)arg, "11") == 0)
		return (IND);
	return (0);
}

int				*get_type(unsigned char *board, t_proc *c_proc, int *type)
{
	char		*bitcode;
	char		*first_arg;
	char		*sec_arg;
	char		*third_arg;

	first_arg = (char *)ft_memalloc(sizeof(char) * 4);
	sec_arg = (char *)ft_memalloc(sizeof(char) * 4);
	third_arg = (char *)ft_memalloc(sizeof(char) * 4);
	bitcode = ft_itoabase_imax(board[(c_proc->i + 1) % MEM_SIZE], 2);
	first_arg[0] = bitcode[0];
	first_arg[1] = bitcode[1];
	sec_arg[0] = bitcode[2];
	sec_arg[1] = bitcode[3];
	third_arg[0] = bitcode[4];
	third_arg[1] = bitcode[5];
	type[0] = get_arg_type(first_arg);
	type[1] = get_arg_type(sec_arg);
	type[2] = get_arg_type(third_arg);
	return (type);
}