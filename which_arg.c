/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
