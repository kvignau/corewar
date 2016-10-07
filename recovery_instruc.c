/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_instruc.                                  :+:      :+:    :+:   */
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
			return (1);
		i++;
	}
	return (0);
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

int		check_instruct(char *line, char *name, t_data **data)
{
	char	*args;
	char	**args_tab;

	args = NULL;
	args_tab = NULL;
	if (!(instruc_valid(name)))
		return (0);
	args = ft_strtrim(ft_strsub(line, ft_strlen(name), ft_strlen(line)));
	args_tab = ft_strsplit(args, ',');
	ft_strdel(&args);
	ft_strtrim_tab(args_tab);
	// if (!(nb_arg_valid(name, args_tab)))
	// 	return (0);
	return (1);
}
