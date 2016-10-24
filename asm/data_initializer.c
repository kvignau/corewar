/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:06:04 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:06:16 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

void		ini_tmp2(t_tmp2 *tmp2)
{
	tmp2->trad = NULL;
	tmp2->to_trad = NULL;
}
void		ini_tmp1(t_tmp1 *tmp1)
{
	tmp1->tmp2 = NULL;
	tmp1->nw = NULL;
}

void		ini_sum_args(t_sum_args *data)
{
	data->type = 0;
	data->sum = 0;
}

void		ini_data_line(t_data_line *dline, int index_line)
{
	ft_bzero(dline, sizeof(t_data_line));
	dline->label_called = ft_lstdblnew();
	dline->index = index_line;
}

void		data_initializer(t_data **data)
{
	*data = (t_data *)ft_memalloc(sizeof(t_data));
	if (*data)
	{
		((((*data)->file = (char **)ft_memalloc(sizeof(char *) * BUFF)) == NULL)
		? error(*data, "File malloc error\n") : 0);
		(*data)->line = NULL;
		(*data)->comment = NULL;
		(*data)->name = NULL;
		((((*data)->label_kw = ft_lstdblnew()) == NULL) ?
			error(*data, "label_kw malloc error") : 0);
		((((*data)->lst_recup = ft_lstdblnew()) == NULL) ?
			error(*data, "lst_data malloc error") : 0);
		((((*data)->lst_lines = ft_lstdblnew()) == NULL) ?
			error(*data, "lst_lines malloc error") : 0);
	}
	else
		error(*data, "Couldn't malloc data");
}

void	ini_lab(t_lab *lab, t_data **data)
{
	lab = (t_lab *)ft_memalloc(sizeof(t_lab));
	if (lab == NULL)
	{
		error(*data, "File malloc error\n");
		return ;
	}
}

