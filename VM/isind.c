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

unsigned int		isind(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	unsigned int		result;
	unsigned int		start;

	result = 0;
	start = 0;
	start = bit_cat(board, c_proc, 2, 2);
	result = ((bit_cat(board, c_proc, start + 2, IND_SIZE)));
	return (result);
}
