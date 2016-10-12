/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
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
		tmp = tmp->next;
	}
	return (1);
}

int		save_label(char *name, t_data **data)
{
	t_lab	lab;

	ini_lab(&lab, data);
	lab.name = ft_strdup(name);
	if (exist_label(name, data))
	{
		ft_putstr("IN\n");
		ft_lstdbladd_head((*data)->label_kw, &lab, sizeof(t_lab));
	}
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

int		check_label(char *name, t_data **data)
{
	t_recup		recup;

	ft_bzero(&recup, sizeof(t_recup));
	recup.label = 1;
	name = ft_strsub(name, 0, ft_strlen(name) - 1);
	ft_printf("Op: %s\n",name); //debug
	if (!(label_valid(name)))
		return (0);
	save_label(name, data); // a voir
	recup.label_name = ft_strdup(name);
	ft_lstdbladd_head((*data)->lst_data, &recup, sizeof(t_recup));
	return (1);
}

int		check_line(char *line, t_data **data)
{
	int		i;
	char	*name;
	int		ret;

	i = 0;
	ret = 0;
	while (line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_strsub(line, 0, i);
	ft_printf("Op: %s\n",name); //debug
	if (name[ft_strlen(name) - 1] == ':')
		ret = check_label(name, data);
	else
		ret = check_instruct(line, name, data);
	ft_strdel(&name);
	return (ret);
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
			ft_putstr("Line analysed :\n"); //debug
			ft_printf("%s\n",data->file[i]); //debug
			if (!(check_line(data->file[i], &data)))
				return ;
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
	show_label_lst(data->label_kw);
	show_lst_data(data->lst_data);
}
