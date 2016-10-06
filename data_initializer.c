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
		(*data)->file = (char **)ft_memalloc(sizeof(char *) * BUFF);
	}
	(*data)->lst_op = ft_lstdblnew();
}

void		ini_op(t_dbllist **lst_op)
{
	// lst_op = (t_dbllist **)malloc(sizeof(t_dbllist *) * (17));
	// if (lst_op == NULL)
	// 	return ;
	// ft_putstr("lst_op ini\n");
	ft_printf("%s\n", op_tab[0].name);
}
