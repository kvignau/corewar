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

int		set_up_ncurses(t_cor *core)
{
	WINDOW		*gauche;
	WINDOW		*droite;
	// unsigned char *board_empty;
	int i;

	// board_empty = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	// i = -1;
	// while (++i < 4096){
	// 	board_empty[i] = 0;
	// }

	initscr();
	noecho();
	curs_set(0);
	timeout(0);
	core->delay_cycle = 0;//rend le getch non bloquant si si
	gauche= subwin(stdscr, 66, 195, 0, 0);// Créé une fenêtre de 66 lignes et de 195 colonnes en 0, 0
	droite= subwin(stdscr, 66, 50, 0, 195);
	
	box(gauche, ACS_VLINE, ACS_HLINE);// contour de la box
	box(droite, ACS_VLINE, ACS_HLINE);
	

	// print_board(gauche, NULL, board_empty);

	mvwprintw(droite, 1, 2, "nb proc");	
	wrefresh(droite);

	core->windows[0] = gauche;
	core->windows[1] = droite;
	return (0);
}
