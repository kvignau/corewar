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

void		data_initializer(t_data **data)
{
	*data = (t_data *)ft_memalloc(sizeof(t_data));
	if (*data)
	{
		((((*data)->file = (char **)ft_memalloc(sizeof(char *) * BUFF)) == NULL)
		? error(*data, "File malloc error\n") : 0);
		(*data)->comment = NULL;
		(*data)->name = NULL;
		(*data)->nb_lines = 0;
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
