/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		nb_arg(char **args_tab)
{
	int		i;

	i = 0;
	while (args_tab[i])
		i++;
	return (i);
}

int		recover_args(char **args_tab, int *to_check)
{
	int		i;
	int		type;

	i = 0;
	type = 0;
	while (args_tab[i])
	{
		// ft_printf("%s\n", args_tab[i]); //debug
		type = 0;
		if ((type = define_type_args(args_tab[i])) == 0)
			return (0);
		// ft_printf("type : %d\n", type);
		if (i == 0)
			(*to_check) = type;
		else if (i == 1)
			(*to_check) = (*to_check) | (type << 4);
		else if (i == 2)
			(*to_check) = (*to_check) | (type << 8);
		else
			return (0);
		i++;
	}
	ft_printf("to_check : %d\n", (*to_check));
	return (*to_check);
}

int		valid_args(char **args_tab, int op_code, int *to_check)
{
	int		i;
	int		type;

	i = 0;
	type = 0;
	if (!(type = recover_args(args_tab, to_check)))
		return (0);
	if (!(verif_type(type, op_code)))
		return (0);
	return (1);
}

int		check_args(char **args_tab, int op_code, t_data **data)
{
	int		to_check;

	to_check = 0;
	if (nb_arg(args_tab) != op_tab[op_code - 1].nb_param)
	{
		error(*data, "Nb param of instruc wrong");
		return (0);
	}
	if (!(valid_args(args_tab, op_code, &to_check)))
		return (0);
	return (1);
}
