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

void	intro(t_dbllist *champ_list)
{
	t_elem	*tmp;
	int		i;

	i = 1;
	tmp = champ_list->head;
	ft_printf("Introducing contestants...\n");
	while (tmp != NULL)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n", i,
			(((t_champ *)(tmp->content))->size),
			(((t_champ *)(tmp->content))->name),
			(((t_champ *)(tmp->content))->comment));
		tmp= tmp->next;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_cor		core;
	t_options	options;
	t_dbllist	*champ_list;
	char		*board;
	t_elem		*tmp;

	//char str[] = "00ea83f3";

	ft_bzero(&core, sizeof(t_cor));
	ft_bzero(&options, sizeof(t_options));
	champ_list = ft_lstdblnew();
	if (!corewar_usage(argc))
		return (-1);
	if (options_checkers(argc, argv, &options, champ_list) == 0)
		return (0);
	tmp = champ_list->head;
	int i = 1;
	ft_printf("size : %d\n",(t_champ *)(champ_list->length));
	while (tmp != NULL)
	{
		ft_printf("champ:[%d], name:[%s] nb: [%d]\n", i, (((t_champ *)(tmp->content))->name),(((t_champ *)(tmp->content))->vm_number));
		i++;
		tmp= tmp->next;
	}
	intro(champ_list);
	board = memory();
	//set_champion_on_board(champ_list);
	return (0);
}
