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
	unsigned char *board;
	int i;

	board = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	i = -1;
	while (++i < 4096){
		board[i] = 0;
	}
		
	initscr();
	noecho();
	gauche= subwin(stdscr, 66, 195, 0, 0);// Créé une fenêtre de 66 lignes et de 195 colonnes en 0, 0
	droite= subwin(stdscr, 66, 50, 0, 195);
	
	box(gauche, ACS_VLINE, ACS_HLINE);// contour de la box
	box(droite, ACS_VLINE, ACS_HLINE);
	
	while (1)
	{
		print_board(gauche, board);

		mvwprintw(droite, 1, 2, "Ceci est la fenetre de droite");	
		wrefresh(droite);

		if (getch() == ' ')
			break ;
	}
	windows[0] = gauche;
	windows[1] = droite;
	// endwin();
	
	// free(gauche);
	// free(droite);
	return (0);
}

int main(void) {
	WINDOW		*windows[2];
	unsigned char *board;
	int i;



	set_up_ncurses(windows);

	board = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	board[0] = 9;
	board[1] = 0x42;
	board[2] = 10;
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

