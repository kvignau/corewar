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
	ft_printf("define_index\n");
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
	ft_printf("i_called : %d\n", *i_called);
	ft_printf("i_declared : %d\n", *i_declared);

}

void	trad_to_ok(t_elem *elem, t_dbllist **lst_lines, char *lbl_called)
{
	t_elem	*tmp;

	tmp = (((t_data_line *)((elem)->content)))->label_called->tail;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_called *)((tmp)->content))->name, lbl_called) == 0)
			((t_called *)((tmp)->content))->trad = 1;
		tmp = tmp->prev;
	}
}

int		not_already_trad(t_elem *elem, t_dbllist **lst_lines, char *lbl_called)
{
	t_elem	*tmp;

	tmp = (((t_data_line *)((elem)->content)))->label_called->tail;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_called *)((tmp)->content))->name, lbl_called)
			&& ((t_called *)((tmp)->content))->trad == 0)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

int		front_decl(t_dbllist **lst_lines, int i_called, int i_declared)
{
	t_elem	*tmp;
	int		nb_oct;

	ft_putstr(">>>>>>>>>>>>>>>>>>>>>>>>>>>> Front DECL\n");
	tmp = (*lst_lines)->tail;
	nb_oct = 0;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->index == i_called)
			// && not_already_trad(tmp, lst_lines, lbl_called))
		{
			// ft_printf("<><><><><><><><><><><><><><><>\n");
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

int		back_decl(char *lbl_called, t_dbllist **lst_lines, int i_called, int i_declared)
{
	ft_putstr(">>>>>>>>>>>>>>>>>>>>>>>>>>>> Back DECL\n");
	t_elem	*tmp;
	int		nb_oct;

	tmp = (*lst_lines)->tail;
	nb_oct = 0;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->index == i_declared)
			// && not_already_trad(tmp, lst_lines, lbl_called))
		{
			// trad_to_ok(tmp, lst_lines, lbl_called);
			nb_oct = ((t_data_line *)((tmp)->content))->nb_oct;
			ft_printf("nb_oct 1 : %d\n", nb_oct);
			tmp = tmp->prev;
			while (tmp != NULL)
			{
				if (((t_data_line *)((tmp)->content))->index == i_called)
					break ;
				else
					nb_oct += ((t_data_line *)((tmp)->content))->nb_oct;
				ft_printf("nb_oct 2 : %d\n", nb_oct);
				tmp = tmp->prev;
			}
		}
		tmp = tmp->prev;
	}
	nb_oct--;
	ft_printf("nb_oct 3 : %d\n", nb_oct);
	return (65535 - nb_oct);
}

char	*trad_label_called(char *lbl_called, char **tmp_trad, t_data **data)
{
	ft_printf("lbl_called : %s\n", lbl_called);
	int		i_called;
	int		i_declared;
	char	*tmp;

	i_called = 0;
	i_declared = 0;
	tmp = NULL;
	ft_printf("TRAD LABEL\n");
	if (exist_label(lbl_called, data))
		return (NULL);
	define_index(lbl_called, data, &i_called, &i_declared);
	if (i_called < i_declared)
		tmp = ft_itoabase_imax(front_decl(&((*data)->lst_lines), i_called, i_declared), 16);
	else
		tmp = ft_itoabase_imax(back_decl(lbl_called, &((*data)->lst_lines), i_called, i_declared), 16);
	hex_to_lower(&tmp);
	add_zero(&tmp, 4);
	return (tmp);
}

// void	trad_dir_label(t_data **data)
// {
// 	t_elem	*tmp;

// 	tmp = ((*data)->lst_recup)->tail;
// 	while (tmp != NULL)
// 	{
// 		if (((t_recup *)((tmp)->content))->lst_hexa)
// 		{
// 			lsthexa_tostr(((t_recup *)((tmp)->content))->lst_hexa);
// 		}
// 		tmp = tmp->prev;
// 	}
// }

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
	tmp = ft_strjoin(first, trad);
	ft_strdel(&first);
	*tmp_trad = ft_strjoin(tmp, last);
	ft_strdel(&tmp);
	ft_strdel(&last);
	ft_printf("first : %s\nlast : %s\n", first, last);
	ft_printf("trad : %s\n", *tmp_trad);
}

void	trad_dir_label(t_data **data)
{
	int		i;
	int		j;
	char	*to_trad;
	char	*trad;

	i = 0;
	j = 0;
	to_trad = NULL;
	trad = NULL;
	while ((*data)->tmp_trad[i])
	{
		if ((*data)->tmp_trad[i] == '%')
		{
			j = i + 1;
			while ((*data)->tmp_trad[j] != '!')
				j++;
			to_trad = ft_strsub((*data)->tmp_trad, i + 2, j - (i + 2));
			if ((trad = trad_label_called(to_trad, &((*data)->tmp_trad), data)) == NULL)
				break ;

			ft_printf(">>>>>>>>>>>>>>>>> TRAD : %s\n", trad);
			modif_trad(i, j, trad, &((*data)->tmp_trad));
			ft_strdel(&trad);
			ft_strdel(&to_trad);
		}
		j = 0;
		i++;
	}
}

//INTEGRER LA TRAD DU LABEL DANS LE TMP_CHAR
// FAIRE TRAD BACK DU LABEL
