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

static void	set_new_era(t_cor *core, t_dbllist *pr_list)
{
	t_elem			*tmp;

	tmp = pr_list->head;
	core->cycles_to_die -= CYCLE_DELTA;
	core->era_cycles = 0;
	core->era_lives_counter = 0;
	if (core->cycles_to_die < 0)
		core->cycles_to_die = 0;
	core->check = 0;
	while (tmp != NULL)
	{
		((t_proc *)(tmp->content))->live = 0;
		tmp = tmp->next;
	}
	// ft_printf("***************************NEW ERA SET***************************\n");
}

static void	check_winner(t_cor *core, t_dbllist *ch_list)
{
	char			*name;
	t_elem			*tmp;

	tmp = ch_list->head;
	while(tmp != NULL)
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

int		main(int argc, char **argv)
{
	t_cor			core;
	t_options		options;
	t_dbllist		*champ_list;
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
	core.options = options;
	core.board = memory();
	core.cycles_to_die = CYCLE_TO_DIE;
	core.cycles = 0;
	intro(champ_list);
	init_board(champ_list, process_list, &(core.board), &core);
	// tmp2 = champ_list->head;
	// ft_printf("champ:[0], name:[%s] nb: [%d]\n", (((t_champ *)(tmp2->content))->name),(((t_champ *)(tmp2->content))->vm_number));
	while (1)
	{
		ft_printf("core_cycles [%d]  ", core.cycles);
		if (options.bool_dump == 1 && core.cycles == options.dump_number)
		{
			ft_printf("\n");
			ft_print_memory(core.board, MEM_SIZE);
			break ;
		}
		if(core.cycles_to_die == 0 || (core.era_cycles % core.cycles_to_die) == 0)
		{
			execute_dead_process(&process_list, &core);
			// ft_printf("process_list size :  %d\n", process_list->length);
			if (process_list->length == 0)
				break ;
			if (core.era_lives_counter >= NBR_LIVE || (core.check + 1) == MAX_CHECKS)
			{
				// ft_printf("OLD ERA era_lives_counter: [%d]   core.check: [%d]   core.era_to_die [%d] core.cycles_to_die [%d]\n",
					// core.era_lives_counter, core.check, core.cycles_to_die, core.cycles_to_die);
				set_new_era(&core, process_list);
				// ft_printf("NEW ERA era_lives_counter: [%d]   core.check: [%d]   core.era_to_die [%d] core.cycles_to_die [%d]\n",
					// core.era_lives_counter, core.check, core.cycles_to_die, core.cycles_to_die);
			}
			else
			{
				// ft_printf("NOPE    ERA era_lives_counter: [%d]   core.check: [%d]   core.era_to_die [%d] core.cycles_to_die [%d]\n",
					// core.era_lives_counter, core.check, core.cycles_to_die, core.cycles_to_die);
				core.check += 1;
			}
			core.era_lives_counter = 0;
		}
		tmp = process_list->head;
		while (tmp != NULL)
		{
			if (iscmd(tmp->content, &core, champ_list, process_list) == 0)
				next_pc(1, tmp->content, core.board);
			tmp = tmp->next;
		}
		core.cycles += 1;
		// if (opt_verbose == 1)
			ft_printf("It is now cycle %d\n", core.cycles);
		core.era_cycles += 1;
	}
	check_winner(&core, champ_list);
	// ft_print_memory(core.board, MEM_SIZE);
	/*while (tmp != NULL && tmp2 != NULL)
	{
		ft_printf("champ:[%d], name:[%s] nb: [%d]\n", i, (((t_champ *)(tmp->content))->name),(((t_champ *)(tmp->content))->vm_number));
		ft_printf("champ:[%d], i:[%d] pc: [%x]\n", i, (((t_proc *)(tmp2->content))->i),(((t_proc *)(tmp2->content))->pc));
		i++;
		cmd_aff(board, tmp2->content);
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}*/
	// ft_printf("size before : %d\n", process_list->length);
	// ft_printf("i:%d, add: {%x}\n", ((t_proc *)(tmp2->content))->i, (((t_proc *)(tmp2->content))->pc));
	 //while (i < 35)
	{
		// cmd_live(core.board, tmp->content, &core, champ_list);
		//cmd_ldi(board, tmp2->content);
		//cmd_st(board, tmp2->content);
		/*cmd_lld(board, tmp2->content);
		cmd_ld(board, tmp2->content);
		cmd_st(board, tmp2->content);
		cmd_ld(board, tmp2->content);
		cmd_st(board, tmp2->content);
		cmd_st(board, tmp2->content);*/
	}
	/*tmp2 = process_list->head;
	ft_printf("size after : %d\n", process_list->length);
	ft_printf("i:%d, add: {%x}\n", ((t_proc *)(tmp2->content))->i, (((t_proc *)(tmp2->content))->pc));
	tmp2 = process_list->head->next;
	ft_printf("size after : %d\n", process_list->length);*/
	// ft_print_memory(core.board, MEM_SIZE);


	return (0);
}
