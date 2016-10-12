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

int		check_instruct(char *line, char *name, t_data **data)
{
	char	*args;
	// char	**args_tab;
	// int		op_code;
	t_recup	recup;

	args = NULL;
	// args_tab = NULL;
	// op_code = 0;
	ft_bzero(&recup, sizeof(t_recup));
	if ((recup.op_code = instruc_valid(name)) == -1)
	{
		ft_printf("Instruction's name incorrect\n");
		return (0);
	}
	args = ft_strtrim(ft_strsub(line, ft_strlen(name), ft_strlen(line)));
	recup.args_tab = ft_strsplit(args, ',');
	ft_strdel(&args);
	ft_strtrim_tab(recup.args_tab);
	if (!(check_args(recup.args_tab, recup.op_code, data)))
	{
		free_tab_char(&recup.args_tab);
		return (0);
	}
	ft_lstdbladd_head((*data)->lst_data, &recup, sizeof(t_recup));
	return (1);
}
