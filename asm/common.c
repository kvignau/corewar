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
	while (args_tab[i])
	{
		tmp = ft_strtrim(args_tab[i]);
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

//faire fonction de remplissage de 0
// %label sur 2
// %nb sur 4

void	add_zero(char **str, int width)
{
	char	*zero;
	char	*tmp;
	char	i;

	zero = NULL;
	tmp = NULL;
	i = 0;
	if (ft_strlen(*str) == width)
		return ;
	zero = ft_strdup("0");
	while (ft_strlen(*str) < width)
	{
		tmp = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(zero, tmp);
		ft_strdel(&tmp);
	}
}

int		find_in_tb_char(char *name, char **label_called)
{
	int		i;

	i = 0;
	while (label_called[i] != NULL)
	{
		if (ft_strcmp(label_called[i], name) == 0)
			return (1);
		i++;
	}
	return (0);
}
