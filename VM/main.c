/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:48:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 18:15:04 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



int		main(int argc, char **argv)
{
	t_cor			core;
	t_options		options;
	t_dbllist		*champ_list;
	unsigned char	*board;
	t_elem			*tmp;

	ft_bzero(&core, sizeof(t_cor));
	ft_bzero(&options, sizeof(t_options));
	champ_list = ft_lstdblnew();
	if (!corewar_usage(argc))
		return (-1);
	if (options_checkers(argc, argv, &options, champ_list) == 0)
		return (0);
	tmp = champ_list->head;
	int i = 1;
	ft_printf("size : %d\n",(champ_list->length));
	/*while (tmp != NULL)
	{
		ft_printf("champ:[%d], name:[%s] nb: [%d]\n", i, (((t_champ *)(tmp->content))->name),(((t_champ *)(tmp->content))->vm_number));
		i++;
		tmp= tmp->next;
	}*/
	intro(champ_list);
	board = memory();
	set_champions_on_board(champ_list, &board);
	ft_print_memory(board, MEM_SIZE);
	return (0);
}
