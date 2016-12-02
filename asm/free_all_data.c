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

static void	free_lst_called(t_dbllist **lst)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*lst)->head;
	while (tmp != NULL)
	{
		if (((t_called *)((tmp)->content))->name)
			ft_strdel(&((t_called *)((tmp)->content))->name);
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*lst)->tail = NULL;
	(*lst)->head = NULL;
	free(*lst);
	*lst = NULL;
}

static void	free_lst_lines(t_dbllist **lst)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*lst)->head;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->label_declared)
			ft_strdel(&((t_data_line *)((tmp)->content))->label_declared);
		if (((t_data_line *)((tmp)->content))->label_called)
			free_lst_called(&((t_data_line *)((tmp)->content))->label_called);
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*lst)->tail = NULL;
	(*lst)->head = NULL;
	free(*lst);
	*lst = NULL;
}

static void	free_lst_recup(t_dbllist **lst)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*lst)->head;
	while (tmp != NULL)
	{
		if (((t_recup *)((tmp)->content)))
			free_t_recup(((t_recup *)((tmp)->content)));
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	free(tmp);
	tmp = NULL;
	(*lst)->tail = NULL;
	(*lst)->head = NULL;
	free(*lst);
	*lst = NULL;
}

static void	free_label_kw(t_dbllist **lst)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*lst)->head;
	while (tmp != NULL)
	{
		if (((t_lab *)((tmp)->content))->name)
			ft_strdel(&(((t_lab *)((tmp)->content))->name));
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*lst)->tail = NULL;
	(*lst)->head = NULL;
	free(*lst);
	*lst = NULL;
}

void		free_all_data(t_data *data)
{
	if (data != NULL)
	{
		((data->file != NULL)
			? ft_free2dtab((void **)data->file, data->nb_lines) : 0);
		((data->line != NULL) ? ft_memdel((void **)&data->line) : 0);
		((data->comment != NULL) ? ft_memdel((void **)&data->comment) : 0);
		((data->name != NULL) ? ft_memdel((void **)&data->name) : 0);
		if (data->label_kw)
			free_label_kw(&data->label_kw);
		if (data->lst_recup)
			free_lst_recup(&data->lst_recup);
		if (data->lst_lines)
			free_lst_lines(&data->lst_lines);
		if (data->tmp_trad)
			ft_strdel(&data->tmp_trad);
		if (data->trad)
			ft_strdel(&data->trad);
	}
}
