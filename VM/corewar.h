/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:49:16 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/10 11:10:08 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "../libftprintf/includes/ft_printf.h"
# define OPTIONS	"dsnvcaN"
# define REG 1
# define DIR 2
# define IND 3
# include <ncurses.h>

/*
**********************  Structures  **********************
*/

typedef struct		s_options
{
	int				stealth;
	int				bool_dump;
	intmax_t		dump_number;
	int				bool_vm_number;
	unsigned int	vm_number;
	int				verbose;
	int				cycle;
	int				ncurse;
	int				aff;
}					t_options;
typedef struct		s_cor
{
	int				pid;
	int				nb_champ;
	unsigned int	last_live;
	int				cycles_to_die;
	unsigned int	era_lives_counter;
	int				check;
	intmax_t		cycles;
	int				era_cycles;
	unsigned int	winner_nb;
	unsigned char	*board;
	t_options		options;
	int				new_era;
	int				end;
	WINDOW			*windows[2];
	int				cycle_frequency;
	int				u_delta_sleep;
	int				process_map[4096];
	int				color_map[4096];
	int				is_paused;
	int				is_first;
	FILE			*lolol;
}					t_cor;
typedef struct		s_champ
{
	int				id;
	char			*name;
	char			*comment;
	unsigned char	*content;
	unsigned int	vm_number;
	unsigned int	size;
}					t_champ;
typedef struct		s_var
{
	char			*str;
	int				i;
	char			**argv;
	int				error;
}					t_var;
typedef struct		s_proc
{
	int				r[REG_NUMBER];
	int				carry;
	unsigned char	*pc;
	unsigned int	i;
	int				ctp;
	int				live;
	int				pid;
	int				last_lived;
	unsigned char	c_cmd;
	int				color;
	int				error;
}					t_proc;

/*
**********************  Display  **********************
*/

int			corewar_usage(int argc);
void		ft_print_memory(unsigned char *ptr, int memsize);
void		intro(t_dbllist *champ_list);

/*
**********************  Options  **********************
*/

int			options_checkers(int argc, char **argv, t_options *options,
	t_dbllist *champ_list);
void		cmd_verbose(unsigned char *board, t_proc *c_proc, int offset);
void		cmd_verbose_sti(unsigned char *board, t_proc *c_proc, int p1, int p2);
void		cmd_verbose_st(int pid, int reg_nb, int id);
void		cmd_verbose_ld(int pid, int reg_nb, int id);
void		cmd_verbose_zjmp_live(char *cmd, int pid, int id);

/*
**********************  Checkers  **********************
*/

int			champions_maker(t_dbllist *champ_list, t_options *options,
	t_var *var);

/*
**********************  Utils  **********************
*/

uintmax_t		ft_hextoi(unsigned char *str);
char			*ft_hextoa(int *str, int size);
unsigned char	*get_content(int *str, int size);
int				reverse_byte(int buf, int readv);
int				isreg(unsigned char *board, t_proc *c_proc, int *type, int arg_nb);
int				isdir(unsigned char *board, t_proc *c_proc, int *type, int arg_nb);
int				isind(unsigned char *board, t_proc *c_proc, int *type, int arg_nb);

/*
**********************  Memory Setter  **********************
*/

unsigned char	*memory(void);
void			init_board(t_dbllist *ch_list, t_dbllist *pr_list, t_cor *core);

/*
**********************  Commands **********************
*/

void			set_new_era(t_cor *core, t_dbllist *pr_list);
int				execute_dead_process(t_dbllist **pr_list, t_cor *core);
int				iscmd(t_proc *c_proc, t_cor *core, t_dbllist *champ_list, t_dbllist *pr_list);
int				get_cmd_size(int *type, int label_size, int nb_param);
int				*get_type(unsigned char *board, t_proc *c_proc);
int				get_register_name(unsigned char *board, t_proc *c_proc, int i[]);
int				get_arg_val(int oc_trunc, unsigned char *board, t_proc *c_proc, int i[]);
unsigned int	bit_cat(unsigned char *board, t_proc *c_proc, int start, int size);
void			next(unsigned char *board, t_proc *c_proc, int nb, int verbose);
void			next_pc(int counter_offset, t_proc *c_proc, unsigned char *board);
void			cmd_live(unsigned char *board, t_proc *c_proc, t_cor *core,
	t_dbllist *ch_list);
void			cmd_ld(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_st(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_add(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_sub(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_and(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_or(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_xor(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_zjmp(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_ldi(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_sti(unsigned char *board, t_proc *c_proc, t_cor *core);
void			sti_result(t_cor *core, t_proc *c_proc, int reg_nb, unsigned int add);
int				add_ind_reg(unsigned char *board, t_proc *c_proc, int v, int *reg_nb);
int				add_reg_reg(unsigned char *board, t_proc *c_proc, int v, int *reg_nb);
void			cmd_fork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list, t_cor *core);
void			cmd_lld(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_lldi(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_lfork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list, t_cor *core);
void			cmd_aff(unsigned char *board, t_proc *c_proc, t_cor *core);

/*
**********************  Ncurses **********************
*/

int				set_up_ncurses(t_cor *core);
int 			print_board(t_cor *core, t_dbllist *process_list, unsigned char *board);
int				ncurs_finish(t_cor *core);


#endif
