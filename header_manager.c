/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:45:42 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/05 16:45:52 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	mini_iscomment(int *i, int *j)
{
	*i += 1;
	*j = 0;
}

static void	comment_found(t_data *data, int *i, int *j, int *comment)
{
	*j += 8;
	*comment = comment_manager(data, i, j);
	*j += 1;
}

static void	name_found(t_data *data, int *i, int *j, int *name)
{
	*j += 5;
	*name = name_manager(data, i, j);
	*j += 1;
}

int			header_manager(t_data *data)
{
	int		i;
	int		j;
	int		comment;
	int		name;

	i = 0;
	j = 0;
	comment = 0;
	name = 0;
	while (i < data->nb_lines && (comment == 0 || name == 0))
	{
		if (ft_isspace(data->file[i][j]) != 0)
			j++;
		else if (ft_iscomment(data->file[i][j]) != 0 ||
			data->file[i][j] == '\0')
			mini_iscomment(&i, &j);
		else if (ft_strncmp(&data->file[i][j], ".comment", 8) == 0)
			comment_found(data, &i, &j, &comment);
		else if (ft_strncmp(&data->file[i][j], ".name", 5) == 0)
			name_found(data, &i, &j, &name);
		else
			return (0);
	}
	return ((comment == 0 || name == 0) ? 0 : i + 1);
}
