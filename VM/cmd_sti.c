/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:27:08 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/14 16:27:21 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned int		get_arg_value(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
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

static int				valid_opc(unsigned char *board, t_proc *c_proc)
{
	int		cmp;

	cmp = board[(c_proc->i + 1) % MEM_SIZE];
	if (cmp == 0x54 || cmp == 0x58 || cmp == 0x64 || cmp == 0x68 ||
		cmp == 0x74 || cmp == 0x78)
		return (1);
	return (0);
}

void					cmd_sti(unsigned char *board, t_proc *c_proc)
{
	unsigned int		result;
	unsigned int		add;
	int					reg_nb;
	int					i;
	int					*type;
	int					first_arg;

	result = 0;
	add = 0;
	i = 0;
	reg_nb = 0;
	// if (c_proc->ctp == 25)
	{
		type = get_type(board, c_proc);
		// if (valid_opc(board, c_proc) == 1)
		// {
		// }
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0x68)
		{
			add = bit_cat(board, c_proc, 3, 2) + bit_cat(board, c_proc, 5, 2);
			reg_nb = board[(c_proc->i + 2) % MEM_SIZE] - 1;

			result = c_proc->r[reg_nb] >> (8 * (REG_SIZE - 1));
			while (i < REG_SIZE)
			{
				board[(c_proc->i + (add + i)) % MEM_SIZE] = result;
				result = c_proc->r[reg_nb] >> ((8 * (REG_SIZE - 1)) - (8 * (i + 1)));
				i++;
			}
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0x58)
		{
			reg_nb = board[(c_proc->i + 3) % MEM_SIZE] - 1;
			add = c_proc->r[reg_nb] + bit_cat(board, c_proc, 5, 2);
			ft_printf("COUCOU %x\n", add);

			result = c_proc->r[reg_nb] >> (8 * (REG_SIZE - 1));
			while (i < REG_SIZE)
			{
				board[(c_proc->i + (add + i)) % MEM_SIZE] = result;
				result = c_proc->r[reg_nb] >> ((8 * (REG_SIZE - 1)) - (8 * (i + 1)));
				i++;
			}
		}
		
		next_pc(get_cmd_size(type, 2, 3), c_proc, board);
		c_proc->ctp = 0;
	}
	// else
		c_proc->ctp += 1;
}
