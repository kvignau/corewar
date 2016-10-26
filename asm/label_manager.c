/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:56:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/17 15:56:35 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		label_check(int *nb_label, t_data *data, int i)
{
	int		k;

	k = 0;
	while (ft_isspace(data->file[i][k]) || ft_islabelchar(data->file[i][k]))
	{
		k++;
		if (data->file[i][k] == ':')
		{
			*nb_label += 1;
			break ;
		}
	}
	return (1);
}

static int		label_count(int *nb_label, t_data *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < data->nb_lines)
	{
		while (data->file[i][j] != '\0')
		{
			if (data->file[i][j] == ':' && data->file[i][j + 1] != '\0')
				label_check(nb_label, data, i);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int		label_to_line(t_var *var, t_data *data)
{
	var->k = 0;
	while (ft_isspace(data->file[var->i][var->k]) ||
		ft_islabelchar(data->file[var->i][var->k]))
	{
		var->k++;
		if (data->file[var->i][var->k] == ':')
		{
			var->label_cleaned[var->l + 1] =
			ft_strdup(&data->file[var->i][var->k + 1]);
			ft_bzero(&data->file[var->i][var->k + 1],
				ft_strlen(&data->file[var->i][var->k + 1]));
			var->toggle = 1;
			break ;
		}
	}
	return (1);
}

static int		label_cleaner(t_data *data, int nb_label)
{
	t_var	var;

	ft_bzero(&var, sizeof(t_var));
	if ((var.label_cleaned = (char **)ft_memalloc(sizeof(char *) *
		(data->nb_lines + nb_label))) == NULL)
		error(data, "label_cleaned malloc error\n");
	while (var.i < data->nb_lines)
	{
		while (data->file[var.i][var.j] != '\0')
		{
			if (data->file[var.i][var.j] == ':' &&
				data->file[var.i][var.j + 1] != '\0')
				label_to_line(&var, data);
			var.j++;
		}
		var.j = 0;
		var.label_cleaned[var.l] = ft_strdup(data->file[var.i]);
		var.i = var.i + 1;
		var.l += (1 + var.toggle);
		var.toggle = 0;
	}
	ft_free2dtab((void **)data->file, data->nb_lines);
	data->file = var.label_cleaned;
	return (1);
}

int				label_manager(t_data *data)
{
	int		nb_label;
	int		i;

	nb_label = 0;
	i = 0;
	label_count(&nb_label, data);
	label_cleaner(data, nb_label);
	data->nb_lines = data->nb_lines + nb_label;
	return (1);
}
