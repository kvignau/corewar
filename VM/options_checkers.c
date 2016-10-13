/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:06:18 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 19:06:30 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*void		options_initializer(t_options **options)
{
	(*options) = (t_options *)ft_memalloc(sizeof(t_options));
	(*options)->list = 0;
	(*options)->printoff = 0;
	(*options)->nbop = 0;
	(*options)->color = 0;
}*/

int		valid_options(t_var *var, t_options *options, t_dbllist *champlist)
{
	if (var->str[0] == 's')
		options->stealth = 1;
	else if (var->str[0] == 'd' || var->str[0] == 'n')
	{
		if (!var->argv[var->i + 1])
			corewar_usage(0);
		else if (var->str[0] == 'd')
		{
			options->dump = 1;
			var->i += 1;
			options->dump_N = ft_atoi(var->argv[var->i]);
		}
		else if (var->str[0] == 'n')
		{
			var->i += 1;
			options->number = 1;
			options->number_N = ft_atoi(var->argv[var->i]);
			champions_checkers(1);
			options->number = 0;
		}
	}
	else if (var->str[0] != '\0')
		return (0);
	return (1);
}

int		options_checkers(int argc, char **argv, t_options *options, t_dbllist *champ_list)
{
	t_var		var;

	ft_bzero(&var, sizeof(t_var));

	var.i = 1;
	var.argv = argv;
	while (var.i < argc)
	{
		if ((argv[var.i][0] == '-' && argv[var.i][1] && !argv[var.i][2]) &&
			((var.str = ft_strchr(OPTIONS, argv[var.i][1])) != NULL))
		{
			if (!(valid_options(&var, options, champ_list)))
				return (0);
		}
		else
			champions_checkers(2);
		var.i += 1;

	}
	return (1);
}
