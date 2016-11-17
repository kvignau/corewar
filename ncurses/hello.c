#include <stdlib.h>
#include <stdio.h>


#include <ncurses.h>




typedef struct		s_elem
{
	void			*content;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;
typedef struct		s_dbllist
{
	size_t			length;
	struct s_elem	*head;
	struct s_elem	*tail;
}					t_dbllist;
typedef struct		s_proc
{
	int				r[16];
	int				carry;
	unsigned char	*pc;
	int				i;
	int				ctp;
	int				live;
}					t_proc;


int		create_array_process_map(t_dbllist *process_list, int process_map[])
{
	t_elem		*current_node;
	t_proc		*node_proc;
	int			i;

	i = -1;
	if (!process_list || !(process_list->head))
		return (-1);
	while (++i < 4096)
	{
		process_map[i] = 0;
	}
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

int 	print_board(WINDOW *gauche, t_dbllist *process_list, unsigned char *board)
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
	

	print_board(gauche, NULL, board_empty);

	mvwprintw(droite, 1, 2, "Ceci est la fenetre de droite");	
	wrefresh(droite);

	windows[0] = gauche;
	windows[1] = droite;
	return (0);
}

int main(void) {
	WINDOW				*windows[2];
	unsigned char		*board;
	int					i;
	t_dbllist			*process_list;
	t_proc				*prank_proc;


	prank_proc = (t_proc *)malloc(sizeof(t_proc));
	prank_proc->i = 1;


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
	print_board(windows[0], process_list, board);

	getch();

	endwin();
	free(windows[0]);
	free(windows[1]);
	return 0;
}

// int main(void)
// {
//     initscr();

    // attron(A_NORMAL);
//     printw("Texte sans mise en forme\n");

//     attron(A_STANDOUT);
//     printw("Texte en meilleur surlignement\n");
//     attroff(A_STANDOUT);

//     attron(A_REVERSE);
//     printw("Texte en inversion video\n");
//     attroff(A_REVERSE);

//     attron(A_DIM);
//     printw("Texte a moitie brillant\n");
//     attroff(A_DIM);

//     attron(A_BOLD);
//     printw("Texte en gras\n");
//     attroff(A_BOLD);

//     attron(A_UNDERLINE);
//     printw("Texte en souligne\n");
//     attroff(A_UNDERLINE);

//     attron(A_INVIS);
//     printw("Texte invisible\n");
//     attroff(A_INVIS);

//     attron(A_UNDERLINE | A_BOLD); // Pour appliquer plusieurs type de mises en forme, on utilise l'opérateur unaire |
//     printw("Texte en gras souligne\n");
    
//     attron(A_NORMAL);
//     refresh();
//     getch();
//     endwin();
    
//     return 0;
// }