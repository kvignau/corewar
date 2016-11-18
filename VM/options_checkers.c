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

int	valid_options(t_var *var, t_options *options, t_dbllist *champ_list)
{
	if (var->str[0] == 's')
		options->stealth = 1;
	else if (var->str[0] == 'v')
			options->verbose = 1;
	else if (var->str[0] == 'c')
			options->cycle = 1;
	else if (var->str[0] == 'd' || var->str[0] == 'n')
	{
		if (!var->argv[var->i + 1] || !var->argv[var->i + 2])
			corewar_usage(0);
		else if (var->str[0] == 'd')
		{
			options->bool_dump = 1;
			var->i += 1;
			options->dump_number = ft_atoi(var->argv[var->i]);
		}
		else if (var->str[0] == 'n')
		{
			var->i += 1;
			options->bool_vm_number = 1;
			options->vm_number = ft_atoi(var->argv[var->i]);
			var->i += 1;
			var->error = champions_maker(champ_list, options, var);
			options->bool_vm_number = 0;
		}
	}
	else if (var->str[0] != '\0' || var->error == 0)
		return (0);
	return (1);
}

int	options_checkers(int argc, char **argv, t_options *options,
	t_dbllist *champ_list)
{
	t_var		var;

	ft_bzero(&var, sizeof(t_var));
	var.i = 1;
	var.argv = argv;
	var.error = -1;
	while (var.i < argc)
	{
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
