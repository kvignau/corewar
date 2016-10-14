/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_instruc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
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

static void	make_args_tab(char *line, char *name, t_recup *recup)
{
	char	*args;

	args = ft_strtrim(ft_strsub(line, ft_strlen(name), ft_strlen(line)));
	recup->args_tab = ft_strsplit(args, ',');
	ft_strdel(&args);
	ft_strtrim_tab(recup->args_tab);
}

int		check_instruct(char *line, char *name, t_data **data, int *current_oct)
{
	char	*args;
	t_recup	recup;

	args = NULL;
	ft_bzero(&recup, sizeof(t_recup));
	recup.lst_hexa = ft_lstdblnew();
	if ((recup.op_code = instruc_valid(name)) == -1)
		return (0);
	make_args_tab(line, name, &recup);
	if (!(check_args(recup.args_tab, recup.op_code, data)))
	{
		free_tab_char(&recup.args_tab);
		return (0);
	}
	recup.sum = ft_strdup(sum_args(recup.args_tab));
	trad_args(&recup);
	ft_lstdbladd_head((*data)->lst_recup, &recup, sizeof(t_recup));
	return (1);
}


// instr_hex = ft_strdup(ft_itoabase_uimax(recup.op_code, 16));
