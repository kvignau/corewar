/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_register_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/07 15:12:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_register_name(unsigned char *board, t_proc *c_proc, int i[])
{
	int		r_dest;

	r_dest = bit_cat(board, c_proc, i[0], 1);
	i[0] += 1;
	if (r_dest <= 0 || r_dest > REG_NUMBER)
	{
		i[1] = -1;
	}
	return (r_dest);
}
