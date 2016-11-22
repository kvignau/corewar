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

static int		create_array_process_map(t_dbllist *process_list, int process_map[])
{
	t_elem		*current_node;
	t_proc		*node_proc;
	int			i;

	// ft_bzero(process_map, 16384); pas compris pk 16384 et pas 4096 comme si dessous
	while (++i < 4096)
	{
		process_map[i] = 0;
	}
	i = -1;
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

int		print_board(WINDOW *gauche, t_dbllist *process_list, unsigned char *board)
{
	int		i;
	int		j;
	int		process_map[4096];
	int		nb_process_to_diplay;

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

	getch();// stop le programme et attend un input user pour continuer

	return (0);
}