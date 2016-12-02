/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dead_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:16:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/15 18:16:28 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		execute_dead_process(t_dbllist **pr_list, t_cor *core)
{
	t_elem		*tmp;
	t_elem		*tmp_next;

	tmp = (*pr_list)->head;
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		if (((t_proc *)(tmp->content))->live == 0 || core->cycles_to_die <= 0)
		{
			if (core->options.verbose == 1)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					((t_proc *)(tmp->content))->pid,
					((t_proc *)(tmp->content))->last_lived,
					core->cycles_to_die);
			ft_lstdbldelone(pr_list, tmp);
		}
		else
			((t_proc *)(tmp->content))->live = 0;
		tmp = tmp_next;
	}
	if ((*pr_list)->length == 0)
		core->winner_nb = core->last_live;
	return ((*pr_list)->length);
}
