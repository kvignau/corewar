/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_dir_with_label(char *arg)
{
	int		i;
	char	*label;
	int		ret;

	i = 0;
	label = NULL;
	ret = 0;
	if (arg[i] != '%')
		return (0);
	if (arg[++i] == ':')
	{
		label = ft_strsub(arg, i + 1, ft_strlen(arg));
		if (label_valid(label))
			ret = 1;
		ft_strdel(&label);
		return (1);
	}
	return (ret);
}

void	nb_label_called(char **args_tab, int *nb_called)
{
	int		i;

	i = 0;
	while (args_tab[i])
	{
		if (is_dir_with_label(args_tab[i]))
			*nb_called = *nb_called + 1;
		i++;
	}
}

void	label_called(t_data_line *dline, char **args_tab)
{
	int		i;
	int		nb_called;
	int		j;
	char	*label_name;

	i = 0;
	j = 0;
	nb_called = 0;
	label_name = NULL;
	nb_label_called(args_tab, &nb_called);
	if (nb_called != 0)
		dline->label_called = (char **)malloc(sizeof(char *) * nb_called);
	while (args_tab[i])
	{
		if (is_dir_with_label(args_tab[i]))
		{
			label_name = ft_strsub(args_tab[i], 2, ft_strlen(args_tab[i]));
			dline->label_called[j] = ft_strdup(label_name);
			ft_strdel(&label_name);
			j++;
		}
		i++;
	}
}
