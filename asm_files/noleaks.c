/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noleaks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_lst_hexa(t_dbllist **lst_hexa)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*lst_hexa)->head;
	while (tmp != NULL)
	{
		if (((t_hexa *)((tmp)->content))->hexa)
			ft_strdel(&(((t_hexa *)((tmp)->content))->hexa));
		if (((t_hexa *)((tmp)->content))->lbl_name)
			ft_strdel(&(((t_hexa *)((tmp)->content))->lbl_name));
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*lst_hexa)->tail = NULL;
	(*lst_hexa)->head = NULL;
	free(*lst_hexa);
	*lst_hexa = NULL;
}

void	free_t_recup(t_recup *recup)
{
	if (recup->label_name)
		ft_strdel(&(recup->label_name));
	if (recup->args_tab)
	{
		ft_free2dtab((void **)recup->args_tab, nb_arg(recup->args_tab));
	}
	if (recup->lst_hexa)
	{
		free_lst_hexa(&(recup->lst_hexa));
		free((recup->lst_hexa));
		recup->lst_hexa = NULL;
	}
}

void	free_tab_char(char ***tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(tab[i]);
		i++;
	}
}
