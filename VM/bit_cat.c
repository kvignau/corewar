/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:36:32 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/09 13:39:17 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			bit_cat(unsigned char *board, t_proc *c_proc,
	int start, int size)
{
	int	result;
	unsigned int	nb;
	int				i;

	i = 0;
	nb = 0;
	result = 0;
	while (i < size)
	{
		nb = board[((c_proc->i + (start + i)) % MEM_SIZE)];
		result = result | nb;
		if (i < size - 1)
			result = result << 8;
		i++;
	}
	return (result);
}
