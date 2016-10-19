/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:49:16 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 16:46:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "../libftprintf/includes/ft_printf.h"
# define OPTIONS 		"dsn"


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
	unsigned int	*vm_number;
}					t_champ;

typedef struct		s_var
{
	char			*str;
	int				i;
	char			**argv;
}					t_var;

/*
**********************  Display  **********************
*/

int			corewar_usage(int argc);

/*
**********************  Options  **********************
*/

int			options_checkers(int argc, char **argv, t_options *options, t_dbllist *champ_list);

/*
**********************  Checkers  **********************
*/

int			champions_maker(t_dbllist *champ_list, t_options *options, t_var *var);

/*
**********************  Utils  **********************
*/

uintmax_t	ft_hextoi(char *str);

#endif
