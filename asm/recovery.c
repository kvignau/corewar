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

int		exist_label(char *name, t_data **data)
{
	t_elem	*tmp;

	tmp = ((*data)->label_kw)->tail;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_lab *)((tmp)->content))->name, name) == 0)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int		save_label(char *name, t_data **data)
{
	t_lab	lab;

	ini_lab(&lab, data);
	lab.name = ft_strdup(name);
	if (exist_label(name, data))
		ft_lstdbladd_head((*data)->label_kw, &lab, sizeof(t_lab));
	return (1);
}

int		label_valid(char *name)
{
	int		i;

	i = 0;
	while (name[i] != '\0')
	{
		if (!(ft_strchr(LABEL_CHARS, name[i])))
			return (0);
		i++;
	}
	return (1);
}

int		check_label(char *name, t_data **data, t_data_line *dline)
{
	t_recup		recup;

	ft_bzero(&recup, sizeof(t_recup));
	recup.label = 1;
	name = ft_strsub(name, 0, ft_strlen(name) - 1);
	if (!(label_valid(name)))
		return (0);
	if (!(save_label(name, data)))
		return (1);
	recup.label_name = ft_strdup(name);
	dline->label_declared = ft_strdup(name);
	dline->nb_oct = 0;
	ft_lstdbladd_head((*data)->lst_recup, &recup, sizeof(t_recup));
	return (1);
}

int		check_line(char *line, t_data **data)
{
	int				i;
	char			*name;
	t_data_line		dline;
	static int		index_line = 0;

	i = 0;
	name = NULL;
	ft_bzero(&dline, sizeof(t_data_line));
	dline.label_called = ft_lstdblnew();
	dline.index = index_line;
	while (line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_strsub(line, 0, i);
	if (name[ft_strlen(name) - 1] == ':')
	{
		if (check_label(name, data, &dline) == 0)
			return (0);
	}
	else
	{
		if (check_instruct(line, name, data, &dline) == 0)
			return (0);
	}
	ft_strdel(&name);
	// show_dline((*data)->lst_lines);
	ft_lstdbladd_head((*data)->lst_lines, &dline, sizeof(t_data_line));
	index_line += 1;
	return (1);
}

void	recovery(t_data *data)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (i < data->nb_lines)
	{
		if (data->file[i][j] != '\0')
		{
			if (!(check_line(data->file[i], &data)))
				return ;
			j++;
		}
		i++;
		j = 0;
	}
	// show_lst_recup(data->lst_recup); // debug
}
