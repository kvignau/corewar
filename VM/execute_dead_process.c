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

void	execute_dead_process(t_dbllist *pr_list, t_cor *core)
{
	t_elem		*tmp;
	static int i =0;

	i++;
	tmp = pr_list->head;
ft_printf("Hello[%d]\n",i);

	while (tmp != NULL)
	{
		if (((t_proc *)(tmp->content))->live == 0)
			ft_lstdbldelone(&(pr_list), tmp);
		// ft_printf("END\n");
		tmp = tmp->next;
	}
	if (pr_list->length == 0)
		core->winner_nb = core->last_live;
}