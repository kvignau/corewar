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

static int	instruc_valid(char **name)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(g_op_tab[i].name, *name) == 0)
			return (g_op_tab[i].op_code);
		i++;
	}
	ft_strdel(name);
	return (-1);
}

static void	make_args_tab(char *line, char *name, t_recup *recup)
{
	char	*args;
	char	*tmp;

	tmp = ft_strsub(line, ft_strlen(name), ft_strlen(line));
	args = ft_strtrim(tmp);
	free(tmp);
	recup->args_tab = ft_strsplit(args, ',');
	ft_strdel(&args);
	ft_strtrim_tab(recup->args_tab);
}

static int	sum_nb_oct(char *hex)
{
	int		i;
	int		nb_oct;
	int		nb_dir_lbl;

	i = 0;
	nb_oct = 0;
	nb_dir_lbl = 0;
	while (hex[i])
	{
		if (hex[i] == '%')
		{
			while (hex[i] != '!')
				i++;
			nb_dir_lbl++;
		}
		else
			nb_oct++;
		i++;
	}
	return ((nb_oct / 2) + (nb_dir_lbl * 2));
}

int			check_instruct(char *line, char **name, t_data **data,
			t_data_line *dline)
{
	char	*args;
	t_recup	recup;
	t_hexa	hex;

	args = NULL;
	ft_bzero(&recup, sizeof(t_recup));
	ft_bzero(&hex, sizeof(t_hexa));
	recup.lst_hexa = ft_lstdblnew();
	if ((recup.op_code = instruc_valid(name)) == -1)
		return (0);
	trad_name_instruct(recup.op_code, &hex.hexa);
	make_args_tab(line, *name, &recup);
	if (!(check_args(recup.args_tab, recup.op_code, data)))
		return (0);
	if (g_op_tab[recup.op_code - 1].octcod == 1)
		sum_args(&recup, &hex.hexa);
	trad_args(&recup, &hex.hexa, data, recup.op_code);
	dline->nb_oct = sum_nb_oct(hex.hexa);
	label_called(dline, recup.args_tab);
	ft_lstdbladd_head(recup.lst_hexa, &hex, sizeof(t_hexa));
	ft_lstdbladd_head((*data)->lst_recup, &recup, sizeof(t_recup));
	return (1);
}
