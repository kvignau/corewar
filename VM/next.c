/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:41:38 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/22 17:41:45 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		next(unsigned char *board, t_proc *c_proc, int nb, int verbose)
{
	if (verbose == 1)
		cmd_verbose(board, c_proc, nb);
	next_pc(nb, c_proc, board);
}
