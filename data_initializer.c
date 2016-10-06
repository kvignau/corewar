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
		(*data)->file = (char **)ft_memalloc(sizeof(char *) * BUFF);
		(*data)->line = NULL;
		(*data)->comment = NULL;
		(*data)->name = NULL;
	}
	else
		error(*data, "Couldn't malloc data");
}
