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

int			header_manager(t_data *data, int nb_lines)
{
	int		i;
	int		j;
	int		comment;
	int		name;


	i = 0;
	j = 0;
	comment = 0;
	name = 0;
	while (i < nb_lines && (comment == 0 || name == 0))
	{
		if (ft_isspace(data->file[i][j]) != 0)
			j++;
		else if (ft_iscomment(data->file[i][j]) != 0 ||
			data->file [i][j] == '\0')
			mini_iscomment(&i, &j);
		else if (ft_strncmp(&data->file[i][j], ".comment", 8) == 0)
		{
			//comment_found(data, &i, &j, nb_lines);
			j += 8;
			comment = comment_manager(data, &i, &j, nb_lines);
			j++;
		}
		else if (ft_strncmp(&data->file[i][j], ".name", 5) == 0)
		{
			j += 5;
			name = name_manager(data, &i , &j, nb_lines);
			j++;
		}
		else
			return (0);
	}
	return ((comment == 0 || name == 0) ? 0 : i + 1);
}
