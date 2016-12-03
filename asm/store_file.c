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
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error(data, "Open error\n");
	if (data->file != NULL)
	{
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			data->file[*i] = line;
			*i += 1;
			if (*i % 1024 == 0)
				(((data->file = realloc(data->file, 1024)) == NULL) ?
					error(data, "Realloc error\n") : 0);
		}
		((ret == -1) ? error(data, "Read error\n") : 0);
		free(line);
		data->file[*i] = NULL;
	}
	else
		return (0);
	return (1);
}
