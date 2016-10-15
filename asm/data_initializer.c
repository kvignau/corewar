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
		((((*data)->label_unkw = ft_lstdblnew()) == NULL) ?
			error(*data, "label_unkw malloc error") : 0);
		((((*data)->lst_recup = ft_lstdblnew()) == NULL) ?
			error(*data, "lst_data malloc error") : 0);
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

