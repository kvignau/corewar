/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			define_index(char *name, t_data **data, int *i_called,
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

int				already_trad(t_elem *elem, char *lbl_called)
{
	t_elem	*tmp;

	tmp = (((t_data_line *)((elem)->content)))->label_called->tail;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_called *)((tmp)->content))->name, lbl_called) == 0)
		{
			if (((t_called *)((tmp)->content))->trad == 0)
				return (0);
		}
		tmp = tmp->prev;
	}
	return (1);
}

static t_elem	*find_elem_caller(char *lbl_called, t_dbllist **lst_lines,
				int i_called)
{
	t_elem	*tmp;

	tmp = (*lst_lines)->tail;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->index == i_called)
		{
			if (already_trad(tmp, lbl_called) == 0)
				return (tmp);
		}
		tmp = tmp->prev;
	}
	return (NULL);
}

void			trad_to_ok(t_dbllist **lst_lines, char *lbl_called,
				int i_called)
{
	t_elem	*tmp;
	t_elem	*elem;

	elem = find_elem_caller(lbl_called, lst_lines, i_called);
	tmp = (((t_data_line *)((elem)->content)))->label_called->tail;
	if (elem == NULL)
		return ;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_called *)((tmp)->content))->name, lbl_called) == 0
			&& ((t_called *)((tmp)->content))->trad == 0)
			((t_called *)((tmp)->content))->trad = 1;
		tmp = tmp->prev;
	}
}

void			modif_trad(int i, int j, char *trad, char **tmp_trad)
{
	char	*first;
	char	*last;
	char	*tmp;

	first = NULL;
	last = NULL;
	tmp = NULL;
	first = ft_strsub(*tmp_trad, 0, i);
	last = ft_strsub(*tmp_trad, j + 1, ft_strlen(*tmp_trad) - j);
	ft_strdel(tmp_trad);
	tmp = ft_strjoinandfree(first, trad, 1);
	*tmp_trad = ft_strjoinandfree(tmp, last, 3);
}
