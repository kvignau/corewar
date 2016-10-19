/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	define_index(char *name, t_data **data, int *i_called,
		int *i_declared)
{
	if ((*i_called = index_label_called(name, (*data)->lst_lines)) == -1)
	{
		error(*data, "label error\n");
		return ;
	}
	if ((*i_declared = index_label_declared(name, (*data)->lst_lines)) == -1)
	{
		error(*data, "label error\n");
		return ;
	}
}

int		front_decl(t_dbllist *lst_lines, int i_called, int i_declared)
{
	ft_putstr("Front DECL\n");
	return (1);
}

int		back_decl(t_dbllist *lst_lines, int i_called, int i_declared)
{
	ft_putstr("Front DECL\n");
	return (1);
}
