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

static void		dump(t_var *var, t_options *options)
{
	options->bool_dump = 1;
	var->i += 1;
	options->dump_number = ft_atoi(var->argv[var->i]);
}

static void		set_num(t_var *var, t_options *options, t_dbllist *champ_list)
{
	var->i += 1;
	options->bool_vm_number = 1;
	options->vm_number = ft_atoi(var->argv[var->i]);
	var->i += 1;
	var->error = champions_maker(champ_list, options, var);
	options->bool_vm_number = 0;
}

static int		valid_options(t_var *var, t_options *options,
	t_dbllist *champ_list)
{
	if (var->str[0] == 's')
		options->stealth = 1;
	else if (var->str[0] == 'v')
		options->verbose = 1;
	else if (var->str[0] == 'c')
		options->cycle = 1;
	else if (var->str[0] == 'a')
		options->aff = 1;
	else if (var->str[0] == 'N')
		options->ncurse = 1;
	else if (var->str[0] == 'd' || var->str[0] == 'n')
	{
		if (!var->argv[var->i + 1] || !var->argv[var->i + 2])
			corewar_usage(0);
		else if (var->str[0] == 'd')
			dump(var, options);
		else if (var->str[0] == 'n')
			set_num(var, options, champ_list);
	}
	else if (var->str[0] != '\0' || var->error == 0)
		return (0);
	return (1);
}

static void		too_many_champ(t_var *var)
{
	ft_putstr("Please input a maximum of four champions.\n");
	var->error = 0;
}

int				options_checkers(int argc, char **argv, t_options *options,
	t_dbllist *champ_list)
{
	t_var		var;

	ft_bzero(&var, sizeof(t_var));
	var.i = 1;
	var.argv = argv;
	var.error = -1;
	while (var.i < argc)
	{
		if (champ_list->length >= 4)
			too_many_champ(&var);
		if (var.error == 0)
			return (0);
		if ((argv[var.i][0] == '-' && argv[var.i][1] && !argv[var.i][2]) &&
			((var.str = ft_strchr(OPTIONS, argv[var.i][1])) != NULL))
		{
			if (!(valid_options(&var, options, champ_list)))
				return (0);
		}
		else
			var.error = champions_maker(champ_list, options, &var);
		var.i += 1;
	}
	if (var.error == 0)
		return (0);
	return (1);
}
