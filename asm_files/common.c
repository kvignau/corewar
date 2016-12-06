/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_strtrim_tab(char **args_tab)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (args_tab && args_tab[i])
	{
		tmp = ft_strtrim(args_tab[i]);
		free(args_tab[i]);
		args_tab[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
}

int		nb_arg(char **args_tab)
{
	int		i;

	i = 0;
	while (args_tab[i])
		i++;
	return (i);
}

void	hex_to_lower(char **hex)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while ((*hex)[i])
	{
		if (ft_isupper((*hex)[i]))
		{
			c = ft_tolower((*hex)[i]);
			(*hex)[i] = c;
		}
		i++;
	}
}

void	add_zero(char **str, int width)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strlen(*str) == (size_t)width)
		return ;
	while (ft_strlen(*str) < (size_t)width)
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoinandfree("0", tmp, 2);
	}
}

int		find_in_lst_called(char *name, t_dbllist *label_called)
{
	t_elem	*tmp;

	tmp = label_called->tail;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_called *)((tmp)->content))->name, name) == 0
			&& ((t_called *)((tmp)->content))->trad == 0)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}
