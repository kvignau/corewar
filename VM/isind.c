/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:50:41 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/14 10:50:48 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					isind(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	int				result;
	unsigned int	id;

	result = 0;
	if (arg_nb == 2)
	{
		if (type[0] == REG)
		{
			id = bit_cat(board, c_proc, 3, 4);
			result = bit_cat(board, c_proc, id, 4);
		}
		else
		{
			id = bit_cat(board, c_proc, 4, 4);
			result = bit_cat(board, c_proc, id, 4);
		}
	}
	else	
	{
		id = bit_cat(board, c_proc, 2, 2);
		result = bit_cat(board, c_proc, id, 4);
	}
	return (result);
}
