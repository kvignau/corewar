/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:08:16 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 18:08:18 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		dbldelone_end(t_dbllist **list, t_elem *to_remove)
{
	free(to_remove->content);
	free(to_remove);
	(*list)->length--;
}

void			ft_lstdbldelone(t_dbllist **lst, t_elem *to_remove)
{
	t_elem		*tmp;

	tmp = (*lst)->head;
	while (tmp != NULL && tmp != to_remove)
		tmp = tmp->next;
	if (tmp == NULL)
		return ;
	if (tmp == (*lst)->head)
	{
		(*lst)->head = tmp->next;
		tmp->next->prev = NULL;
		tmp->next = NULL;
	}
	else if (tmp == (*lst)->tail)
	{
		(*lst)->tail = tmp->prev;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	dbldelone_end(lst, to_remove);
}
