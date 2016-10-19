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

int		front_decl(t_dbllist *lst_lines, int i_called, int i_declared)
{
	t_elem	*tmp;
	int		nb_oct;

	ft_putstr("Front DECL\n");
	tmp = lst_lines->tail;
	nb_oct = 0;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->index == i_declared)
			break ;
		nb_oct += ((t_data_line *)((tmp)->content))->nb_oct;
		tmp = tmp->prev;
	}
	return (nb_oct);
}

int		back_decl(t_dbllist *lst_lines, int i_called, int i_declared)
{
	ft_putstr("Front DECL\n");
	return (1);
}

static void	trad_label_called(char *lbl_called, char **tmp_trad, t_data **data)
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
		return ;
	ft_printf(">>>>");
	define_index(lbl_called, data, &i_called, &i_declared);
	if (i_called < i_declared)
		tmp = ft_itoabase_imax(front_decl((*data)->lst_lines, i_called, i_declared), 16);
	else
		tmp = ft_itoabase_imax(back_decl((*data)->lst_lines, i_called, i_declared), 16);
	hex_to_lower(&tmp);
	add_zero(&tmp, 4);
	ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>>tmp %s\n", tmp);

}

void	trad_dir_label(t_data **data)
{
	int		i;
	int		j;
	char	*to_trad;

	i = 0;
	j = 0;
	to_trad = NULL;
	while ((*data)->tmp_trad[i])
	{
		if ((*data)->tmp_trad[i] == '%')
		{
			j = i + 1;
			while ((*data)->tmp_trad[j] != '!')
				j++;
			to_trad = ft_strsub((*data)->tmp_trad, i + 2, j - (i + 2));
			trad_label_called(to_trad, &((*data)->tmp_trad), data);
		}
		j = 0;
		i++;
	}
}

//INTEGRER LA TRAD DU LABEL DANS LE TMP_CHAR
// FAIRE TRAD BACK DU LABEL
