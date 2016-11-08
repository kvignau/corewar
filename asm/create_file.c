/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_s_file(char *name)
{
	if (name)
	{
		if (name[ft_strlen(name) - 1] == 's'
			&& name[ft_strlen(name) - 2] == '.')
			return (1);
	}
	return (0);
}

static char		*recup_only_name(char *file_name)
{
	int		i;
	char	*tmp;

	i = ft_strlen(file_name) - 1;
	tmp = NULL;
	while (i >= 0)
	{
		if (file_name[i] == '/')
			break ;
		i--;
	}
	tmp = ft_strsub(file_name, i + 1, ft_strlen(file_name));
	return (tmp);
}

void			create_cor(t_data *data, char *file_name)
{
	int		fd;
	char	*tmp;
	char	*name;

	fd = -1;
	tmp = NULL;
	if (!(check_s_file(file_name)))
		return ;
	tmp = recup_only_name(file_name);
	name = ft_strsub(tmp, 0, ft_strlen(tmp) - 2);
	fd = open(ft_strjoin(name, ".cor"),
		O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(fd);
	open(ft_strjoin(name, ".cor"), O_WRONLY);
	reverse_hexdump(data->tmp_trad, fd);
	close(fd);
}
