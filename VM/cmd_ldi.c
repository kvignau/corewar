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

void	cmd_ldi(unsigned char *board, t_proc *c_proc)
{
	int		result;
	int		ind_value;
	int		start;
	int		*type;

	type = (int *)ft_memalloc(sizeof(int) * 3);
	result = 0;
	start = 0;
	ind_value = 0;
	// if (c_proc->ctp == 25)
	type = get_type(board, c_proc, type);
	ft_printf("YOLO%d, %d\n", type[0], type[1]);
	/*{
		if (board[(c_proc->i + 1) % MEM_SIZE] == 0xe4)
		{

			start = bit_cat(board, c_proc, 2, 2);
			ind_value = bit_cat(board, c_proc, start, IND_SIZE) % (IDX_MOD);


			// if (((bit_cat(board, c_proc, ((bit_cat(board, c_proc, 2, 2)) % IDX_MOD), IND_SIZE) + 1)) % IDX_MOD == 1)
			// 	ind_value = ((bit_cat(board, c_proc, ((bit_cat(board, c_proc, 2, 2)) % IDX_MOD), IND_SIZE) + 1)) / IDX_MOD;
			// else
			// 	ind_value = ((bit_cat(board, c_proc, ((bit_cat(board, c_proc, 2, 2)) % IDX_MOD), IND_SIZE) + 1)) % IDX_MOD;
			ft_printf("Value: %d\n", ind_value);
			ft_printf("Value: %x\n", bit_cat(board, c_proc, 4, 2));

			result = ind_value + bit_cat(board, c_proc, 4, 2);
			c_proc->r[(board[c_proc->i + 6] - 1)] = bit_cat(board, c_proc, (result % IDX_MOD), REG_SIZE);
		}
		else if (board[(c_proc->i + 1) % MEM_SIZE] == 0xa4)
		{
			result = bit_cat(board, c_proc, 2, IND_SIZE) + bit_cat(board, c_proc, 4, 2);
			c_proc->r[(board[c_proc->i + 6] - 1)] = bit_cat(board, c_proc, (result % IDX_MOD), REG_SIZE);
		}
		next_pc(7, c_proc, board);
		c_proc->ctp = 0;
	}
	// else
		c_proc->ctp += 1;*/
}