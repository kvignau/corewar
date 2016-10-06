/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:55:20 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 15:55:48 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		store_file(char **argv, t_data *data, int *i)
{
	int		fd;
	int		ret;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error(data, "Open error\n");
	if (data->file != NULL)
	{
		while ((ret = get_next_line(fd, &data->line)) > 0)
		{
			(((data->file[*i] = ft_strdup(data->line)) == NULL) ?
				error(data, "Malloc error\n") : 0);
			*i += 1;
			if (*i % 1024 == 0)
				(((data->file = realloc(data->file, 1024)) == NULL) ?
					error(data, "Realloc error\n") : 0);
		}
		((ret == -1) ? error(data, "Read error\n") : 0);
	}
	else
		return (0);
	return (1);
}
