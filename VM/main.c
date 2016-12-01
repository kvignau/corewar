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
	core->check = 0;
	while (tmp != NULL)
	{
		((t_proc *)(tmp->content))->live = 0;
		tmp = tmp->next;
	}
		if (core->options.cycle == 1)
	{
		write(1, "Cycle to die is now ", 20);
		ft_putnbr(core->cycles_to_die);
		write(1, "\n", 1);
	}
}

static void	check_winner(t_cor *core, t_dbllist *ch_list)
{
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
	int				i;

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
	core.era_cycles = 0;
	core.cycles = 0;
	core.end = -1;
	i = -1;
	while (++i < MEM_SIZE)
		core.color_map[i] = 0;
	intro(champ_list);
	init_board(champ_list, process_list, &core);
	if (options.ncurse == 1)
	{
		core.options.stealth = 1;
		core.options.aff = 1;
		core.options.verbose = 0;
		core.options.cycle = 0;
		core.options.bool_dump = 0;
		core.options.bool_vm_number = 0;
		set_up_ncurses(&core);
	}
	

	while (1)
	{
		if (core.options.cycle == 1 && core.cycles != 0)
		{
			write(1, "It is now cycle ", 16);
			ft_putnbr(core.cycles);
			write(1, "\n", 1);
		}
	
		tmp = process_list->head;
		while (tmp != NULL)
		{
			if (iscmd(tmp->content, &core, champ_list, process_list) == 0)
				next_pc(1, tmp->content, core.board);
			tmp = tmp->next;
		}
		if (options.ncurse == 1)
		{
			print_board(&core, process_list, core.board);
		}
		if(core.cycles_to_die <= 0 || (((core.era_cycles + 1) % core.cycles_to_die) == 1 && (core.cycles != 0)))
		{

			core.end = execute_dead_process(&process_list, &core);
			if (core.era_lives_counter >= NBR_LIVE || (core.check + 1) == MAX_CHECKS)
				set_new_era(&core, process_list);
			else
				core.check += 1;
			core.era_lives_counter = 0;
		}

		if (options.bool_dump == 1 && core.cycles == options.dump_number)
		{
			ft_print_memory(core.board, MEM_SIZE);
			break ;
		}
		if (process_list)
		{
			tmp = process_list->head;
			while (tmp != NULL)
			{
				((t_proc *)(tmp->content))->last_lived += 1;
				tmp = tmp->next;
			}
		}
		core.cycles += 1;
		core.era_cycles += 1;

		if (core.end == 0)
			break ;
	}
	if (options.ncurse == 1)
		ncurs_finish(&core);
	check_winner(&core, champ_list);

	

	return (0);
}
