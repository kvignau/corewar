/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	define_index(char *name, t_data **data, int *i_called,
		int *i_declared)
{
	if ((*i_called = index_label_called(name, (*data)->lst_lines)) == -1)
	{
		error(*data, "label error\n");
		return ;
	}
	if ((*i_declared = index_label_declared(name, (*data)->lst_lines)) == -1)
	{
		error(*data, "label error\n");
		return ;
	}
}

int		front_decl(t_dbllist *lst_lines, int i_called, int i_declared)
{
	ft_putstr("Front DECL\n");
	return (1);
}

int		back_decl(t_dbllist *lst_lines, int i_called, int i_declared)
{
	ft_putstr("Front DECL\n");
	return (1);
}

static void	trad_label_called(char *lbl_called, char **tmp_trad, t_data **data)
{
	ft_printf("lbl_called : %s\n", lbl_called);
}

void	trad_dir_label(t_data **data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*data)->tmp_trad[i])
	{
		if ((*data)->tmp_trad[i] == '%')
		{
			j = i + 1;
			while ((*data)->tmp_trad[j] != '!')
				j++;
			trad_label_called(ft_strsub((*data)->tmp_trad, i, j - i),
								&((*data)->tmp_trad), data);
			j = 0;
		}
		i++;
	}
}
