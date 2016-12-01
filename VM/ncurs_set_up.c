/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurs_set_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:48:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 18:15:04 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_ncurses()
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	timeout(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int				set_up_ncurses(t_cor *core)
{
	WINDOW		*gauche;
	WINDOW		*droite;

	init_ncurses();
	gauche= subwin(stdscr, 66, 195, 0, 0);
	droite= subwin(stdscr, 66, 50, 0, 195);
	attron(A_STANDOUT);
	box(gauche, ACS_VLINE, ACS_HLINE);
	box(droite, ACS_VLINE, ACS_HLINE);
	core->windows[0] = gauche;
	core->windows[1] = droite;
	core->u_delta_sleep = 0;
	core->cycle_frequency = 1000;
	core->is_paused = 1;
	core->is_first = 1;
	// // debug
	// core->lolol = fopen("dbeug.sms", "w+");
	// fclose(core->lolol);
	return (0);
}
