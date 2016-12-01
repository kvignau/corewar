/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_ind(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && arg[i] == ':')
		{
			if (label_valid(ft_strsub(arg, 1, ft_strlen(arg))))
				return (T_IND);
			else
				return (0);
		}
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		else if (!(ft_isdigit(arg[i])))
			return (0);
		else
			i++;
	}
	return (T_IND);
}

int			is_dir_label(char *arg, char **label)
{
	int		ret;

	ret = 0;
	*label = ft_strsub(arg, 2, ft_strlen(arg));
	if (label_valid(*label))
		ret = 2;
	ft_strdel(label);
	return (ret);
}

int			is_dir(char *arg)
{
	int		i;
	char	*label;

	i = 0;
	label = NULL;
	if (arg[i] != '%')
		return (0);
	if (arg[++i] == ':')
		return (is_dir_label(arg, &label) == 2 ? 2 : 0);
	while (arg[i])
	{
		if (i == 1 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		else if (!(ft_isdigit(arg[i])))
			return (0);
		else
			i++;
	}
	return (T_DIR);
}

int			is_reg(char *arg)
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
	if (i > 3)
		return (0);
	return (T_REG);
}
