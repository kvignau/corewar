#include <stdlib.h>
#include <stdio.h>


#include <ncurses.h>

int 	print_board(WINDOW *gauche, unsigned char *board)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			mvwprintw(gauche, 1 + i, 2 + (j * 3), "%.2x", board[i*64 + j]);
		}
	}
	wrefresh(gauche);

	return (0);
}



int		set_up_ncurses(WINDOW *windows[])
{
	WINDOW		*gauche;
	WINDOW		*droite;
	unsigned char *board_empty;
	int i;

	board_empty = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	i = -1;
	while (++i < 4096){
		board_empty[i] = 0;
	}

	initscr();
	noecho();
	gauche= subwin(stdscr, 66, 195, 0, 0);// Créé une fenêtre de 66 lignes et de 195 colonnes en 0, 0
	droite= subwin(stdscr, 66, 50, 0, 195);
	
	box(gauche, ACS_VLINE, ACS_HLINE);// contour de la box
	box(droite, ACS_VLINE, ACS_HLINE);
	

	print_board(gauche, board_empty);

	mvwprintw(droite, 1, 2, "Ceci est la fenetre de droite");	
	wrefresh(droite);

	windows[0] = gauche;
	windows[1] = droite;
	return (0);
}

int main(void) {
	WINDOW		*windows[2];
	unsigned char *board;
	int i;



	set_up_ncurses(windows);

	board = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	board[0] = 3;
	board[1] = 0x84;
	board[2] = 31;
	board[3] = 1;
	i = -1;
	while (++i < 4092){
		board[4 + i] = 0;
	}
	print_board(windows[0], board);

	getch();

	endwin();
	free(windows[0]);
	free(windows[1]);
	return 0;
}

