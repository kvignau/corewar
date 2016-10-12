/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:20:44 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/06 14:20:52 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_all_data(t_data *data)
{
	if (data != NULL)
	{
		((data->file != NULL) ? ft_free2dtab((void **)data->file, data->nb_lines) : 0);
		((data->line != NULL) ? ft_memdel((void **)&data->line) : 0);
		((data->comment != NULL) ? ft_memdel((void **)&data->comment) : 0);
		((data->name != NULL) ? ft_memdel((void **)&data->name) : 0);
	}
}