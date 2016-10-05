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
	data->cleanfile = cleaned_file;
	ft_free2dtab((void **)data->file, nb_lines);
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
	data->tmpfile = trimmed_file;
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
		if (data->tmpfile[i][0] == '#' || data->tmpfile[i][0] == ';')
			i++;
		else
		{
			sharp_cleaned[j] = ft_strdup(data->tmpfile[i]);
			j++;
			i++;
		}
	}
	*nb_lines = j;
	data->file = sharp_cleaned;
	ft_free2dtab((void **)data->tmpfile, *nb_lines);
	return (1);
}

int		comment_manager(t_data *data, int *i, int *j, int nb_lines)
{
	int		comment_size;

	comment_size = 0;
	data->comment = (char *)ft_memalloc(sizeof(char) * 2049);
	while (data->file[*i][*j] == ' ' || data->file[*i][*j] == '\t')
		*j += 1;
	if (data->file[*i][*j] == '"')
	{
		*j += 1;
		while (data->file[*i][*j] != '"' && comment_size <= 2048 && *i <= nb_lines)
		{
			if (data->file[*i][*j] == '\0')
			{
				*i += 1;
				*j = 0;
			}
			else
			{
				data->comment[comment_size] = data->file[*i][*j];
				*j += 1;
				comment_size++;
			}
		}
	}
	else
	{
		return (0);
	}
	if (comment_size > 2048 || *i >= nb_lines)
		return (0);
	return (1);
}

int		name_manager(t_data *data, int *i, int *j, int nb_lines)
{
	int		name_size;

	name_size = 0;
	data->name = (char *)ft_memalloc(sizeof(char) * 129);
	while (data->file[*i][*j] == ' ' || data->file[*i][*j] == '\t')
		*j += 1;
	if (data->file[*i][*j] == '"')
	{
		*j += 1;
		while (data->file[*i][*j] != '"' && name_size <= 128 && *i <= nb_lines)
		{
			if (data->file[*i][*j] == '\0')
			{
				*i += 1;
				*j = 0;
			}
			else
			{
				data->name[name_size] = data->file[*i][*j];
				*j += 1;
				name_size++;
			}
		}
	}
	else
		return (0);
	if (name_size > 128 || *i >= nb_lines)
		return (0);
	return (1);
}

int		header_manager(t_data *data, int nb_lines)
{
	int		i;
	int		j;
	int		k;
	int		comment;
	int		name;


	i = 0;
	j = 0;
	k = 0;
	comment = 0;
	name = 0;
	while (i < nb_lines && (comment == 0 || name == 0))
	{
		if (ft_isspace(data->file[i][j]) != 0)
			j++;
		else if (ft_iscomment(data->file[i][j]) != 0 ||
			data->file [i][j] == '\0')
		{
			i++;
			j = 0;
		}
		else if (ft_strncmp(&data->file[i][j], ".comment", 8) == 0)
		{
			j += 8;
			comment = comment_manager(data, &i, &j, nb_lines);
			j++;
		}
		else if (ft_strncmp(&data->file[i][j], ".name", 5) == 0)
		{
			j += 5;
			name = name_manager(data, &i , &j, nb_lines);
			j++;
		}
		else
			return (0);
	}
	return ((comment == 0 || name == 0) ? 0 : i + 1);

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
	return (0);
}