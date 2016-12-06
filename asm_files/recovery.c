/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_line(char *line, t_data **data)
{
	int				i;
	char			*name;
	t_data_line		dline;
	static int		index_line = 0;

	i = 0;
	name = NULL;
	ini_data_line(&dline, index_line);
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_strsub(line, 0, i);
	if (name[ft_strlen(name) - 1] == ':')
	{
		if (check_label(&name, data, &dline) == 0)
			return (0);
	}
	else
	{
		if (check_instruct(line, &name, data, &dline) == 0)
			return (0);
	}
	ft_strdel(&name);
	ft_lstdbladd_head((*data)->lst_lines, &dline, sizeof(t_data_line));
	index_line += 1;
	return (1);
}

int				recovery(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_lines)
	{
		if (data->file[i] == NULL)
			return (1);
		if (!(check_line(data->file[i], &data)))
			return (0);
		i++;
	}
	return (1);
}
