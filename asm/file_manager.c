/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:30:43 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:30:57 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

static void			comment_remover(t_data *data, int i, int j)
{
	int		k;

	k = 0;
	while (k < ft_strlen(&data->file[i][j]))
	{
		data->file[i][j + k] = '\0';
		k++;
	}
}

static int			comment_cleaner(t_data *data)
{
	char	**cleaned_file;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((cleaned_file =
		(char **)ft_memalloc(sizeof(char *) * data->nb_lines)) == NULL)
		error(data, "Cleaned_file malloc error\n");
	while (i < data->nb_lines)
	{
		while (data->file[i][j] != '\0')
		{
			if (data->file[i][j] == ';')
				comment_remover(data, i, j);
			j++;
		}
		cleaned_file[i] = ft_strdup(data->file[i]);
		i++;
		j = 0;
	}
	ft_free2dtab((void **)data->file, data->nb_lines);
	data->file = cleaned_file;
	return (1);
}

static int			file_trimer(t_data *data, int *nb_lines, int i)
{
	char	**trimmed_file;
	int		j;

	j = 0;
	if ((trimmed_file =
		(char **)ft_memalloc(sizeof(char *) * *nb_lines)) == NULL)
		error(data, "Trimmed_file malloc error\n");
	while (j < *nb_lines)
	{
		trimmed_file[j] = ft_strtrim(data->file[i]);
		i += 1;
		j++;
	}
	ft_free2dtab((void **)data->file, *nb_lines);
	data->file = trimmed_file;
	return (1);
}

static int			sharp_cleaner(t_data *data, int *nb_lines)
{
	int		i;
	int		j;
	char	**sharp_cleaned;

	i = 0;
	j = 0;
	if ((sharp_cleaned =
		(char **)ft_memalloc(sizeof(char *) * *nb_lines)) == NULL)
		error(data, "Sharp_cleaned malloc error\n");
	while (i < *nb_lines)
	{
		if (!(data->file[i][0] == '#' || data->file[i][0] == ';' ||
			data->file[i][0] == '\0'))
		{
			(((sharp_cleaned[j] = ft_strdup(data->file[i])) == NULL) ?
				error(data, "Malloc error\n") : 0);
			j++;
		}
		i++;
	}
	ft_free2dtab((void **)data->file, *nb_lines);
	*nb_lines = j;
	data->file = sharp_cleaned;
	return (1);
}



int					file_manager(t_data *data, int nb_lines)
{
	int i;

	i = 0;
	data->nb_lines = nb_lines;
	if ((i = header_manager(data)) == 0)
		error(data, "Header error\n");
	data->nb_lines = data->nb_lines - i;
	file_trimer(data, &data->nb_lines, i);
	sharp_cleaner(data, &data->nb_lines);
	comment_cleaner(data);
	file_trimer(data, &data->nb_lines, 0);
	label_manager(data);
	file_trimer(data, &data->nb_lines, 0);
	return (1);
}
