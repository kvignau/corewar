/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:57:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/05 16:57:23 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		name_manager(t_data *data, int *i, int *j, int nb_lines)
{
	int		name_size;

	name_size = 0;
	data->name = (char *)ft_memalloc(sizeof(char) * 129);
	while (data->file[*i][*j] == ' ' || data->file[*i][*j] == '\t')
		*j += 1;
	if (data->file[*i][*j] == '"')
	{
		*j += 1;
		while (data->file[*i][*j] != '"' && name_size <= 128 && *i <= nb_lines)
		{
			if (data->file[*i][*j] == '\0')
			{
				*i += 1;
				*j = 0;
			}
			else
			{
				data->name[name_size] = data->file[*i][*j];
				*j += 1;
				name_size++;
			}
		}
	}
	else
		return (0);
	if (name_size > 128 || *i >= nb_lines)
		return (0);
	return (1);
}