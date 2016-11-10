/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:42:37 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/09 13:42:48 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		isreg(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	unsigned int		result;
	unsigned int		reg_nb;

	result = 0;
	reg_nb = 0;
	if (arg_nb == 2)
	{
		if (type[0] == REG)
			reg_nb = bit_cat(board, c_proc, 3, 1);
		else
			reg_nb = bit_cat(board, c_proc, 4, 1);
		if (reg_nb > 16)
				return (0);
		result = (unsigned int)c_proc->r[reg_nb - 1];
	}
	else
	{
		reg_nb = bit_cat(board, c_proc, 2, 1);
		if (reg_nb > 16)
				return (0);
		result = (unsigned int)c_proc->r[reg_nb - 1];
	}
	return (result);
}

unsigned int		isdir(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	unsigned int		result;

	result = 0;
	if (arg_nb == 2)
	{
		if (type[0] == REG)
			result = (bit_cat(board, c_proc, 3, 2));
		else
			result = bit_cat(board, c_proc, 4, 2);
	}
	else
		result = (bit_cat(board, c_proc, 2, 2));
	return (result);
}

unsigned int		isind(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	unsigned int		result;
	unsigned int		start;

	result = 0;
	start = 0;
	start = bit_cat(board, c_proc, 2, 2);
	result = ((bit_cat(board, c_proc, start + 2, IND_SIZE)) % IDX_MOD);
	return (result);
}

unsigned int		get_arg_value(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	if (type[arg_nb - 1] == REG)
		return(isreg(board, c_proc, type, arg_nb));
	else if (type[arg_nb - 1] == DIR)
		return (isdir(board, c_proc, type, arg_nb));
	else if (type[arg_nb - 1] == IND)
		return (isind(board, c_proc, type, arg_nb));
	else
		return (0);
}

void	cmd_ldi(unsigned char *board, t_proc *c_proc)
{
	unsigned int		result;
	unsigned int		reg_nb;
	int					*type;
	int					first_arg;


	result = 0;
	reg_nb = 0;
	if (c_proc->ctp == 25)
	{
		type = get_type(board, c_proc);
		result = get_arg_value(board, c_proc, type, 1) + get_arg_value(board, c_proc, type, 2);
		reg_nb = bit_cat(board, c_proc, get_cmd_size(type, 2) - 1, 1);
		if (reg_nb > 16)
			return ;
		c_proc->r[reg_nb - 1] = bit_cat(board, c_proc, (result) % IDX_MOD, REG_SIZE);
		next_pc(get_cmd_size(type, 2), c_proc, board);
		c_proc->ctp = 0;
	}
	else
		c_proc->ctp += 1;
}