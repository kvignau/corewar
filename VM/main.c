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

static void	check_winner(t_cor *core, t_dbllist *ch_list)
{
	t_elem			*tmp;

	tmp = ch_list->head;
	while (tmp != NULL)
	{
		if (core->winner_nb == ((t_champ *)(tmp->content))->vm_number)
		{
			ft_printf("le joueur %d(%s) a gagne\n",
				((t_champ *)(tmp->content))->id,
				((t_champ *)(tmp->content))->name);
		}
		tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_cor			core;
	t_options		options;
	t_dbllist		*champ_list;
	t_dbllist		*process_list;

	ft_bzero(&core, sizeof(t_cor));
	ft_bzero(&options, sizeof(t_options));
	champ_list = ft_lstdblnew();
	process_list = ft_lstdblnew();
	if (!corewar_usage(argc))
		return (-1);
	if (options_checkers(argc, argv, &options, champ_list) == 0)
		return (0);
	init(&core, &options);
	intro(champ_list);
	init_board(champ_list, process_list, &core);
	while (game_loop(&core, champ_list, process_list) != 1)
		;
	if (options.ncurse == 1)
		ncurs_finish(&core);
	check_winner(&core, champ_list);
	return (0);
}
