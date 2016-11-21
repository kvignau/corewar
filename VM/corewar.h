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
# define OPTIONS	"dsnvc"
# define REG 1
# define DIR 2
# define IND 3


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
	int				i;
	int				ctp;
	int				live;
	int				pid;
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
unsigned int	isreg(unsigned char *board, t_proc *c_proc, int *type, int arg_nb);
unsigned int	isdir(unsigned char *board, t_proc *c_proc, int *type, int arg_nb);
unsigned int	isind(unsigned char *board, t_proc *c_proc, int *type, int arg_nb);

/*
**********************  Memory Setter  **********************
*/

unsigned char	*memory(void);
void			init_board(t_dbllist *ch_list, t_dbllist *pr_list, t_cor *core);

/*
**********************  Commands **********************
*/

int				execute_dead_process(t_dbllist *pr_list, t_cor *core);
int				iscmd(t_proc *c_proc, t_cor *core, t_dbllist *champ_list, t_dbllist *pr_list);
int				get_cmd_size(int *type, int label_size, int nb_param);
int				*get_type(unsigned char *board, t_proc *c_proc);
int				get_register_name(unsigned char *board, t_proc *c_proc, int i[]);
int				get_arg_val(int oc_trunc, unsigned char *board, t_proc *c_proc, int i[]);
unsigned int	bit_cat(unsigned char *board, t_proc *c_proc, int start, int size);

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
void			sti_result(unsigned char *board, t_proc *c_proc, int reg_nb, unsigned int result);
void			add_ind_reg(unsigned char *board, t_proc *c_proc);
void			add_reg_reg(unsigned char *board, t_proc *c_proc);
void			cmd_fork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list, t_cor *core);
void			cmd_lld(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_lldi(unsigned char *board, t_proc *c_proc, t_cor *core);
void			cmd_lfork(unsigned char *board, t_proc *c_proc, t_dbllist *pr_list, t_cor *core);
void			cmd_aff(unsigned char *board, t_proc *c_proc, t_cor *core);

#endif
