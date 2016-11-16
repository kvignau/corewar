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

int		execute_dead_process(t_dbllist *pr_list, t_cor *core)
{
	t_elem		*tmp;
	static int i =0;

	i++;
	tmp = pr_list->head;
	while (tmp != NULL)
	{
		if (((t_proc *)(tmp->content))->live == 0)
			ft_lstdbldelone(&(pr_list), tmp);
		tmp = tmp->next;
	}
	if (pr_list->length == 0)
		core->winner_nb = core->last_live;
	return (pr_list->length);
}