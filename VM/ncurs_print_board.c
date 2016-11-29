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
	wattron(core->windows[1], A_BOLD);
	mvwprintw(core->windows[1], 1, 2, "nb proc: %d   :) ", process_list->length);
	if (core->cycle_frequency == 1000)
		mvwprintw(core->windows[1], 2, 2, "cycle_frequency: MAX   :D   ");
	else
		mvwprintw(core->windows[1], 2, 2, "cycle_frequency: %d   :D ", core->cycle_frequency);
	mvwprintw(core->windows[1], 3, 2, "nb_cycles_achieved: %d  :X ", core->nb_cycles_achieved);
	wrefresh(core->windows[1]);
	wattroff(core->windows[1], A_BOLD);
	return (0);
}

static int		handle_cycle_celerity(char c_input, t_cor *core)
{
	if (c_input == 'r' && core->cycle_frequency < 1000)
	{
		core->cycle_frequency += 10;
		if (core->cycle_frequency > 1000)
			core->cycle_frequency = 1000;
	}
	else if (c_input == 'e' && core->cycle_frequency < 1000)
	{
		core->cycle_frequency += 1;
		if (core->cycle_frequency > 1000)
			core->cycle_frequency = 1000;
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

static int		create_array_process_map(t_dbllist *process_list, int process_map[], t_cor *core)
{
	t_elem		*current_node;
	t_proc		*node_proc;
	int			i;

	i = -1;
	while (++i < 4096)
		process_map[i] = 0;
	if (!process_list || !(process_list->head))
		return (-1);

	current_node = ((t_elem *)process_list->head);
	while (current_node != NULL)
	{
		if ((node_proc = current_node->content) == NULL)
			return (-1);
		i = node_proc->i % 4096;
		while (i < 0)
			i += 4096;
		process_map[i] = 1;
		current_node = current_node->next;
	}
	return (0);
}

int		print_board(t_cor *core, t_dbllist *process_list, unsigned char *board)
{
	int		i;
	int		j;
	int		nb_process_to_diplay;
	WINDOW	*gauche;
	char	c = 'a';

	gauche = core->windows[0];
	create_array_process_map(process_list, core->process_map, core);
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			if (core->process_map[i * 64 + j])
				wattron(gauche, A_STANDOUT);
			if (core->color_map[i * 64 + j])
				wattron(gauche, COLOR_PAIR(core->color_map[i * 64 + j]));
			mvwprintw(gauche, 1 + i, 2 + (j * 3), "%.2x", board[i * 64 + j]);
			wattroff(gauche, A_STANDOUT);
			wattroff(gauche, COLOR_PAIR(core->color_map[i * 64 + j]));
			attron(A_NORMAL);
		}
	}
	wrefresh(gauche);


	if (core->is_first)
	{
		print_menu(core, process_list);
		core->is_first = 0;
	}
// core->lolol = fopen("dbug.sms", "a");
// fprintf(core->lolol, "1\n");
// fclose(core->lolol);
	if ((c = getch()) == ' ' || core->is_paused)
	{
// core->lolol = fopen("dbug.sms", "a");
// fprintf(core->lolol, "2\n");
// fclose(core->lolol);
		core->is_paused = 1;
		timeout(-1);
		while (((c = getch()) != ' ' && c != 's'))
		{
// core->lolol = fopen("dbug.sms", "a");
// fprintf(core->lolol, "3\n");
// fclose(core->lolol);
			handle_cycle_celerity(c, core);
			print_menu(core, process_list);
		}
		if (c == ' ')
			core->is_paused = 0;
		timeout(0);
	}
	else
		handle_cycle_celerity(c, core);
	core->nb_cycles_achieved += 1;
	print_menu(core, process_list);
	if (core->cycle_frequency < 1000)
		usleep(core->u_delta_sleep);
	return (0);
}





