/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:50:58 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/27 19:51:07 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	content_to_board(t_elem *champ, unsigned char *board,
	t_dbllist *ch_list, t_proc *proc)
{
	int		i;
	int		j;
	int		k;
	unsigned char *str;

	i = (((MEM_SIZE) / ch_list->length) *
		((((t_champ *)(champ->content))->id) - 1));
	proc->i = i;
	j = 0;
	str =(unsigned char *)ft_memalloc(3);
	proc->pc = &board[i];
	proc->live = 0;
	proc->ctp = 0;
	while (j < (((t_champ *)(champ->content))->size) * 2)
	{
		str[0] = (((t_champ *)(champ->content))->content[j]);
		str[1] = (((t_champ *)(champ->content))->content[j + 1]);
		board[i] = (unsigned char)ft_hextoi(str);
		j += 2;
		i += 1;
	}
	proc->r[0] = (((t_champ *)(champ->content))->vm_number);
}

void		init_board(t_dbllist *ch_list, t_dbllist *pr_list,
	unsigned char **board, t_cor *core)
{
	t_elem	*champ;
	t_proc	proc;

	champ = ch_list->head;
	bzero(&proc, sizeof(t_proc));
	while (champ != NULL)
	{
		content_to_board(champ, *board, ch_list, &proc);
		ft_lstdbladd_head(pr_list, (t_proc *)&proc, sizeof(t_proc));
		core->last_live = ((t_champ *)champ->content)->vm_number;
		champ = champ->next;
	}
}
