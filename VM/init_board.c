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
	t_dbllist *ch_list)
{
	int		i;
	int		j;
	unsigned char *str;

	i = (((MEM_SIZE) / ch_list->length) *
		((((t_champ *)(champ->content))->id) - 1));
	j = 0;
	str =(unsigned char *)ft_memalloc(3);
	while (j < (((t_champ *)(champ->content))->size) * 2)
	{
		str[0] = (((t_champ *)(champ->content))->content[j]);
		str[1] = (((t_champ *)(champ->content))->content[j + 1]);
		board[i] = (unsigned char)ft_hextoi(str) ;
		j += 2;
		i += 1;
	}
}

void		init_board(t_dbllist *ch_list, t_dbllist *pr_list,
	unsigned char **board)
{
	t_elem	*champ;
	t_elem	*proc;

	champ = ch_list->head;
	bzero(proc, sizeof())
	while (champ != NULL)
	{
		content_to_board(champ, *board, ch_list);
		tmp = tmp->next;
	}


}
