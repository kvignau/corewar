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

static void	gotonextline(int *i, int *j)
{
	*i += 1;
	*j = 0;
}

static void	savename(t_data *data, int *name_size, int *i, int *j)
{
	data->name[*name_size] = data->file[*i][*j];
	*j += 1;
	*name_size += 1;
}

int			name_manager(t_data *data, int *i, int *j)
{
	int		name_size;

	name_size = 0;
	if ((data->name = (char *)ft_memalloc(sizeof(char) * 129)) == NULL)
		error(data, "data->name malloc error\n");
	while (data->file[*i][*j] == ' ' || data->file[*i][*j] == '\t')
		*j += 1;
	if (data->file[*i][*j] == '"')
	{
		*j += 1;
		while (data->file[*i][*j] != '"' && name_size <= 128 &&
			*i <= data->nb_lines)
		{
			if (data->file[*i][*j] == '\0')
				gotonextline(i, j);
			else
				savename(data, &name_size, i, j);
		}
	}
	else
		return (0);
	if (name_size > 128 || *i >= data->nb_lines)
		return (error(data, ".name is too long (MAX 128 chars)\n"));
	return (1);
}
