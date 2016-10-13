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
#define COREWAR_H

# include "op.h"
# include "../libftprintf/includes/ft_printf.h"

# define OPTIONS "dsn"

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
	int				dump;
	intmax_t		dump_N;
	int				number;
	unsigned int	number_N;
}					t_options;

typedef struct		s_champ
{
	char			*name;
	unsigned int	*champ_id;
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

int					corewar_usage(int argc);

/*
**********************  Options  **********************
*/

int					options_checkers(int argc, char **argv, t_options *options, t_dbllist *champ_list);
int					champions_checkers(int bob);

#endif
