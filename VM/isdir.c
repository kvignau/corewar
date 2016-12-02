/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:51:19 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/14 10:51:26 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			isdir(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	int		result;

	result = 0;
	if (arg_nb == 2)
	{
		if (type[0] == REG)
			result = (bit_cat_no_mod(board, c_proc, 3, 2));
		else
			result = bit_cat_no_mod(board, c_proc, 4, 2);
	}
	else
		result = (bit_cat_no_mod(board, c_proc, 2, 2));
	return (result);
}
