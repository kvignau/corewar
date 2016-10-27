/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:52:58 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/27 19:53:21 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	intro(t_dbllist *champ_list)
{
	t_elem	*tmp;

	tmp = champ_list->head;
	ft_printf("Introducing contestants...\n");
	while (tmp != NULL)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			(((t_champ *)(tmp->content))->id),
			(((t_champ *)(tmp->content))->size),
			(((t_champ *)(tmp->content))->name),
			(((t_champ *)(tmp->content))->comment));
		tmp= tmp->next;
	}
}
