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

char	**file_trimer(t_data *data, int nb_lines)
{
	int		i;
	char	**trimmed_file;

	i = 0;
	trimmed_file = (char **)ft_memalloc(sizeof(char *) * nb_lines);
	while (i < nb_lines)
	{
		trimmed_file[i] = ft_strtrim(data->file[i]);
		i++;
	}
	return (trimmed_file);
}

char	**sharp_cleaner(t_data *data, int nb_lines)
{
	int		i;
	int		j;
	int		k;
	char	**sharp_cleaned;

	i = 0;
	j = 0;
	k = 0;
	sharp_cleaned = (char **)ft_memalloc(sizeof(char *) * nb_lines);

	while (i < nb_lines)
	{
		if (data->file[i][0] == '#' || data->file[i][0] == ';')
			i++;
		else
		{
			sharp_cleaned[j] = ft_strdup(data->file[i]);
			j++;
			i++;
		}
	}
	return (sharp_cleaned);
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
	ft_printf("\033[35mYou're in name\033[0m\n");
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
		ft_printf("i : [%d], j : [%d], com : [%d], name : [%d] \n", i, j, comment, name);
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
			ft_printf("red:\033[31mi : [%d], j : [%d], com : [%d], name : [%d] \033[0m\n", i, j, comment, name);
			j += 8;
			comment = comment_manager(data, &i, &j, nb_lines);
			j++;
			ft_printf("\033[32mDone\033[0m\n");
		ft_printf("\033[33mi : [%d], j : [%d], com : [%d], name : [%d] \033[0m\n", i, j, comment, name);

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
	return (i);

}
int		file_manager(t_data *data, int nb_lines)
{
	int i;

	i = 0;
	ft_printf("hi\n");
	header_manager(data, nb_lines);
	ft_printf("hi\n");

	ft_printf("data->comment :%s\n", data->comment);
	ft_printf("data->name :%s\n", data->name);
	//data->tmpfile = sharp_cleaner(data, nb_lines);

	//data->tmpfile = file_trimer(data, nb_lines);
	//ft_printf("retour de trim \n");
	/*while (i < nb_lines)
	{
		ft_printf ("[%d] %s\n", i, data->tmpfile[i]);
		i++;
	}
	i = 0;*/
	/*while (i++ < nb_lines)
	{
		ft_printf ("[%d] %s\n", i, data->cleanfile[i]);
	}*/
	return (0);
}