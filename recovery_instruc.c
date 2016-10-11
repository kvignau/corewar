/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_instruc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		instruc_valid(char *name)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(op_tab[i].name, name) == 0)
			return (op_tab[i].op_code);
		i++;
	}
	return (-1);
}

void	ft_strtrim_tab(char **args_tab)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (args_tab[i])
	{
		tmp = ft_strtrim(args_tab[i]);
		args_tab[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
}

int		nb_arg(char **args_tab)
{
	int		i;

	i = 0;
	while (args_tab[i])
		i++;
	return (i);
}

int		is_ind(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	return (T_IND);
}

int		is_dir(char *arg)
{
	int		i;
	char	*label;
	int		ret;

	i = 0;
	label = NULL;
	ret = 0;
	if (arg[i] != '%')
		return (0);
	i++;
	if (arg[i] == ':')
	{
		label = ft_strsub(arg, i + 1, ft_strlen(arg));
		if (label_valid(label))
			ret = 2;
		ft_strdel(&label);
		return (ret);
	}
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	return (T_DIR);
}

int		is_reg(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] != 'r')
		return (0);
	i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	return (T_REG);
}

int		define_type_args(char *arg)
{
	int		type;
	int		i;

	type = 0;
	i = 0;
	if (is_reg(arg))
		return (T_REG);
	if (is_ind(arg))
		return (T_IND);
	if (is_dir(arg))
		return (T_DIR);
	return (0);
}

int		valid_args(char **args_tab, int op_code, int *to_check)
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
	{
		error(*data, "Wrong param type");
		return (0);
	}
	return (1);
}

int		check_instruct(char *line, char *name, t_data **data)
{
	char	*args;
	char	**args_tab;
	int		op_code;

	args = NULL;
	args_tab = NULL;
	op_code = 0;
	if ((op_code = instruc_valid(name)) == -1)
		return (0);
	args = ft_strtrim(ft_strsub(line, ft_strlen(name), ft_strlen(line)));
	args_tab = ft_strsplit(args, ',');
	ft_strdel(&args);
	ft_strtrim_tab(args_tab);
	if (!(check_args(args_tab, op_code, data)))
	{
		free_tab_char(&args_tab);
		return (0);
	}
	return (1);
}
