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
	if (core->is_paused)
		mvwprintw(core->windows[1], 2, 3, " ** PAUSED ** ");
	else
		mvwprintw(core->windows[1], 2, 3, " ** RUNNING ** ");
	mvwprintw(core->windows[1], 4, 3, "Processes : %d   ",
		process_list->length);
	if (core->cycle_frequency == 1000)
		mvwprintw(core->windows[1], 6, 3, "Cycles/second limit : MAX     ");
	else
		mvwprintw(core->windows[1], 6, 3, "Cycles/second limit : %d    ",
			core->cycle_frequency);
	mvwprintw(core->windows[1], 8, 3, "Cycle : %d  :X ", core->cycles);
	wrefresh(core->windows[1]);
	wattroff(core->windows[1], A_BOLD);
	return (0);
}

static int		handle_cycle_celerity(char c_input, t_cor *core)
{
	if (c_input == 'r' && core->cycle_frequency < 1000)
		core->cycle_frequency += 10;
	else if (c_input == 'e' && core->cycle_frequency < 1000)
		core->cycle_frequency += 1;
	else if (c_input == 'w' && core->cycle_frequency > 1)
		core->cycle_frequency -= 1;
	else if (c_input == 'q' && core->cycle_frequency > 1)
		core->cycle_frequency -= 10;
	if (core->cycle_frequency > 1000)
		core->cycle_frequency = 1000;
	else if (core->cycle_frequency < 1)
		core->cycle_frequency = 1;
	core->u_delta_sleep = 1000000 / core->cycle_frequency;
	flushinp();
	return (0);
}

static int		create_array_process_map(t_dbllist *process_list,
	int process_map[])
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

static void		print_b(t_cor *core, t_dbllist *proc_l, unsigned char *board)
{
	int		i;
	int		j;

	WINDOW * gauche;
	gauche = core->windows[0];
	create_array_process_map(proc_l, core->process_map);
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
		print_menu(core, proc_l);
}

int				print_board(t_cor *core, t_dbllist *process_list,
	unsigned char *board)
{
	char	c;

	print_b(core, process_list, board);
	if (core->is_first)
		core->is_first = 0;
	if ((c = getch()) == ' ' || core->is_paused)
	{
		core->is_paused = 1;
		timeout(-1);
		print_menu(core, process_list);
		while (((c = getch()) != ' ' && c != 's'))
		{
			handle_cycle_celerity(c, core);
			print_menu(core, process_list);
		}
		if (c == ' ')
			core->is_paused = 0;
		timeout(0);
	}
	else
		handle_cycle_celerity(c, core);
	print_menu(core, process_list);
	if (core->cycle_frequency < 1000)
		usleep(core->u_delta_sleep);
	return (0);
}
