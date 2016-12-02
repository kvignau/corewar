/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:06:04 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:06:16 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void		ini_lab(t_lab *lab, t_data **data)
{
	ft_bzero(lab, sizeof(t_lab));
	if (lab == NULL)
	{
		error(*data, "File malloc error\n");
		return ;
	}
}
