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

int		already_trad(t_elem *elem, t_dbllist **lst_lines, char *lbl_called)
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
			if (already_trad(tmp, lst_lines, lbl_called) == 0)
				return (tmp);
		}
		tmp = tmp->prev;
	}
	return (NULL);
}

static void	trad_to_ok(t_dbllist **lst_lines, char *lbl_called, int i_called)
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

int		front_decl(char *lbl_called, t_dbllist **lst_lines, int i_called,
		int i_declared)
{
	t_elem	*tmp;
	int		nb_oct;

	tmp = (*lst_lines)->tail;
	nb_oct = 0;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->index == i_called)
		{
			while (tmp != NULL)
			{
				if (((t_data_line *)((tmp)->content))->index == i_declared)
					break ;
				nb_oct += ((t_data_line *)((tmp)->content))->nb_oct;
			tmp = tmp->prev;
			}
		}
		tmp = tmp->prev;
	}
	return (nb_oct);
}

int		back_decl(char *lbl_called, t_dbllist **lst_lines, int i_called,
		int i_declared)
{
	t_elem	*tmp;
	int		nb_oct;

	tmp = (*lst_lines)->tail;
	nb_oct = 0;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->index == i_declared)
		{
			nb_oct = ((t_data_line *)((tmp)->content))->nb_oct;
			tmp = tmp->prev;
			while (tmp != NULL)
			{
				if (((t_data_line *)((tmp)->content))->index == i_called)
					break ;
				else
					nb_oct += ((t_data_line *)((tmp)->content))->nb_oct;
				tmp = tmp->prev;
			}
		}
		tmp = tmp->prev;
	}
	nb_oct--;
	return (65535 - nb_oct);
}

char	*trad_label_called(char *lbl_called, char **tmp_trad, t_data **data)
{
	int		i_called;
	int		i_declared;
	char	*tmp;

	i_called = 0;
	i_declared = 0;
	tmp = NULL;
	if (exist_label(lbl_called, data))
		return (NULL);
	define_index(lbl_called, data, &i_called, &i_declared);
	if (i_called < i_declared)
		tmp = ft_itoabase_imax(front_decl(lbl_called, &((*data)->lst_lines), i_called, i_declared), 16);
	else
		tmp = ft_itoabase_imax(back_decl(lbl_called, &((*data)->lst_lines), i_called, i_declared), 16);
	trad_to_ok(&((*data)->lst_lines), lbl_called, i_called);
	hex_to_lower(&tmp);
	add_zero(&tmp, 4);
	return (tmp);
}

void	modif_trad(int i, int j, char *trad, char **tmp_trad)
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

void	trad_dir_label(t_data **data)
{
	int		i;
	int		j;
	t_tmp2	temp;

	i = 0;
	j = 0;
	ini_tmp2(&temp);
	while ((*data)->tmp_trad[i])
	{
		if ((*data)->tmp_trad[i] == '%')
		{
			j = i + 1;
			while ((*data)->tmp_trad[j] != '!')
				j++;
			temp.to_trad = ft_strsub((*data)->tmp_trad, i + 2, j - (i + 2));
			if ((temp.trad = trad_label_called(temp.to_trad, &((*data)->tmp_trad), data)) == NULL)
				break ;
			modif_trad(i, j, temp.trad, &((*data)->tmp_trad));
			ft_strdel(&temp.trad);
			ft_strdel(&temp.to_trad);
		}
		j = 0;
		i++;
	}
}
