/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_era.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 03:35:11 by mchevall          #+#    #+#             */
/*   Updated: 2016/12/02 03:35:20 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_new_era(t_cor *core, t_dbllist *pr_list)
{
	t_elem			*tmp;

	tmp = pr_list->head;
	core->cycles_to_die -= CYCLE_DELTA;
	core->era_cycles = 0;
	core->era_lives_counter = 0;
	core->check = 0;
	while (tmp != NULL)
	{
		((t_proc *)(tmp->content))->live = 0;
		tmp = tmp->next;
	}
		if (core->options.cycle == 1)
	{
		write(1, "Cycle to die is now ", 20);
		ft_putnbr(core->cycles_to_die);
		write(1, "\n", 1);
	}
}
