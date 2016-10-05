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

int		comment_cleaner(t_data *data, int nb_lines)
{
	char	**cleaned_file;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if ((cleaned_file =
		(char **)ft_memalloc(sizeof(char *) * nb_lines)) == NULL)
		return (0);
	while (i < nb_lines)
	{
		while (data->file[i][j] != '\0')
		{
			if (data->file[i][j] == ';')
			{
				while (k < ft_strlen(&data->file[i][j]))
				{
					data->file[i][j + k] = '\0';
					k++;
				}
			}
			j++;
			k = 0;
		}
		cleaned_file[i] = ft_strdup(data->file[i]);
		i++;
		j = 0;
	}
	ft_free2dtab((void **)data->file, nb_lines);
	data->file = cleaned_file;
	return (1);
}

int		file_trimer(t_data *data, int *nb_lines, int *i)
{
	char	**trimmed_file;
	int		j;

	j = 0;
	if ((trimmed_file =
		(char **)ft_memalloc(sizeof(char *) * *nb_lines)) == NULL)
		return (0);
	while (j < *nb_lines)
	{
		trimmed_file[j] = ft_strtrim(data->file[*i]);
		*i += 1;
		j++;
	}
	ft_free2dtab((void **)data->file, *nb_lines);
	data->file = trimmed_file;
	return (1);
}

int		sharp_cleaner(t_data *data, int *nb_lines)
{
	int		i;
	int		j;
	int		k;
	char	**sharp_cleaned;

	i = 0;
	j = 0;
	if ((sharp_cleaned =
		(char **)ft_memalloc(sizeof(char *) * *nb_lines)) == NULL)
		return (0);
	while (i < *nb_lines)
	{
		if (data->file[i][0] == '#' || data->file[i][0] == ';' ||
			data->file[i][0] == '\0')
			i++;
		else
		{
			sharp_cleaned[j] = ft_strdup(data->file[i]);
			j++;
			i++;
		}
	}
	ft_free2dtab((void **)data->file, *nb_lines);
	*nb_lines = j;
	data->file = sharp_cleaned;
	return (1);
}


int		file_manager(t_data *data, int nb_lines)
{
	int i;

	i = 0;
	if ((i = header_manager(data, nb_lines)) == 0)
		return (1);
	nb_lines = nb_lines - i;
	if (!file_trimer(data, &nb_lines, &i))
		return (2);
	if (!sharp_cleaner(data, &nb_lines))
		return (3);
	if (!comment_cleaner (data, nb_lines))
		return (4);
	data->nb_lines = nb_lines;
	return (0);
}