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
	t_dbllist		*process_list;
	t_elem			*tmp;
	t_elem			*tmp2;

	ft_bzero(&core, sizeof(t_cor));
	ft_bzero(&options, sizeof(t_options));
	champ_list = ft_lstdblnew();
	process_list = ft_lstdblnew();
	if (!corewar_usage(argc))
		return (-1);
	if (options_checkers(argc, argv, &options, champ_list) == 0)
		return (0);
	tmp = champ_list->head;
	int i = 1;
	ft_printf("size : %d\n",(champ_list->length));

	intro(champ_list);
	board = memory();
	init_board(champ_list, process_list, &board);
	tmp2 = process_list->head;
	ft_print_memory(board, MEM_SIZE);
	/*while (tmp != NULL && tmp2 != NULL)
	{
		ft_printf("champ:[%d], name:[%s] nb: [%d]\n", i, (((t_champ *)(tmp->content))->name),(((t_champ *)(tmp->content))->vm_number));
		ft_printf("champ:[%d], i:[%d] pc: [%x]\n", i, (((t_proc *)(tmp2->content))->i),(((t_proc *)(tmp2->content))->pc));
		i++;
		cmd_aff(board, tmp2->content);
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}*/
	//cmd_fork()
	return (0);
}
