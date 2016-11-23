/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurs_print_board.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:48:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 18:15:04 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		print_menu(t_cor *core, t_dbllist *process_list)
{
	mvwprintw(core->windows[1], 1, 2, "nb proc: %d   :)", process_list->length);
	mvwprintw(core->windows[1], 2, 2, "cycle_frequency: %d   :D", core->cycle_frequency);
	mvwprintw(core->windows[1], 3, 2, "nb_cycles_achieved: %d  :X", core->nb_cycles_achieved);
	wrefresh(core->windows[1]);
	return (0);
}

static int		handle_cycle_celerity(char c_input, t_cor *core)
{
	if (c_input == 'r')
	{
		core->cycle_frequency += 10;
	}
	else if (c_input == 'e')
	{
		core->cycle_frequency += 1;
	}
	else if (c_input == 'w' && core->cycle_frequency > 1)
	{
		core->cycle_frequency -= 1;
		if (core->cycle_frequency < 1)
			core->cycle_frequency = 1;
	}
	else if (c_input == 'q' && core->cycle_frequency > 1)
	{
		core->cycle_frequency -= 10;
		if (core->cycle_frequency < 1)
			core->cycle_frequency = 1;
	}
	core->u_delta_sleep = 1000000 / core->cycle_frequency;
	flushinp();
	return (0);
}

static int		create_array_process_map(t_dbllist *process_list, int process_map[])
{
	t_elem		*current_node;
	t_proc		*node_proc;
	int			i;

	i = -1;
	while (++i < 4096)
	{
		process_map[i] = 0;
	}
	if (!process_list || !(process_list->head))
		return (-1);

	current_node = process_list->head;
	i = -1;
	while (current_node)
	{
		if (!(node_proc = current_node->content))
			return (-1);
		process_map[node_proc->i] = 1;
		current_node = current_node->next;
	}
	return (0);
}

int		print_board(t_cor *core, t_dbllist *process_list, unsigned char *board)
{
	int		i;
	int		j;
	int		process_map[4096];
	int		nb_process_to_diplay;
	WINDOW	*gauche;
	char	c;

	gauche = core->windows[0];
	create_array_process_map(process_list, process_map);
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			if (process_map[i * 64 + j])
				wattron(gauche, A_STANDOUT);
			mvwprintw(gauche, 1 + i, 2 + (j * 3), "%.2x", board[i * 64 + j]);
			wattroff(gauche, A_STANDOUT);
		}
	}
	wrefresh(gauche);

	if ((c = getch()) == ' ')
	{
		timeout(-1);
		while ((c = getch()) != ' ')
		{
			handle_cycle_celerity(c, core);
			print_menu(core, process_list);
		}
		timeout(0);
	}
	else
		handle_cycle_celerity(c, core);
	print_menu(core, process_list);
	core->nb_cycles_achieved += 1;
	usleep(core->u_delta_sleep);
	return (0);
}





