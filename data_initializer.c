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
		((((*data)->lst_op = ft_lstdblnew()) == NULL) ?
			error(*data, "lst_op malloc error") : 0);
	}
	else
		error(*data, "Couldn't malloc data");
}
