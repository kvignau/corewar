/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:49:16 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/19 16:21:22 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "../libftprintf/includes/ft_printf.h"
# define OPTIONS	"dsn"


/*
**********************  Structures  **********************
*/

typedef struct		s_cor
{
	int				nb_champ;
}					t_cor;
typedef struct		s_options
{
	int				stealth;
	int				bool_dump;
	intmax_t		dump_number;
	int				bool_vm_number;
	unsigned int	vm_number;
}					t_options;
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

/*
**********************  Checkers  **********************
*/

int			champions_maker(t_dbllist *champ_list, t_options *options,
	t_var *var);

/*
**********************  Utils  **********************
*/

uintmax_t			ft_hextoi(unsigned char *str);
char				*ft_hextoa(int *str, int size);
unsigned char		*get_content(int *str, int size);

/*
**********************  Memory Setter  **********************
*/

unsigned char		*memory(void);
void				init_board(t_dbllist *ch_list, t_dbllist *pr_list,
	unsigned char **board);

/*
**********************  Commands **********************
*/

void	next_pc(int counter_offset, t_proc *c_proc, unsigned char *board);
int		cmd_fork(unsigned char *board, t_proc *c_proc);
void	cmd_aff(unsigned char *board, t_proc *c_proc);

#endif
