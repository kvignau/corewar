/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:26:06 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/15 12:26:25 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_vm_number_exist(t_elem *tmp, unsigned int vm_num, t_cor *core)
{
	int				exist;

	exist = 0;
	while(tmp != NULL)
	{
		if (((t_champ *)(tmp->content))->vm_number == vm_num)
		{
			exist = 1;
			if (core->options.stealth == 0)
			ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
				((t_champ *)(tmp->content))->vm_number,
				((t_champ *)(tmp->content))->name);
		}
		tmp = tmp->next;
	}
	return (exist);
}

void			cmd_live(unsigned char *board, t_proc *c_proc, t_cor *core,
	t_dbllist *ch_list)
{
	t_elem			*tmp;
	unsigned int	vm_num_live;

// if (c_proc->ctp == 5)
	{
		tmp = ch_list->head;
		c_proc->live = 1;
		core->current_lives_counter += 1;
		vm_num_live = bit_cat(board, c_proc, 1, 4);
		if (check_vm_number_exist(tmp, vm_num_live, core) == 1)
			core->last_live = vm_num_live;
		next_pc(5 ,c_proc, board);
		c_proc->ctp = 0;
	}
	// else
		c_proc->ctp += 1;
}