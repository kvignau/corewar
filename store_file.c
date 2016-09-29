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

int		store_file(char **argv, t_data *data, int i)
{
	int		fd;

	fd = clean_open(argv[1], O_RDONLY);
	while (get_next_line(fd, &data->line) != 0)
	{
		data->file[i] = ft_strdup(data->line);
		i++;
		if (i % 1024 == 0)
			data->file = ft_realloc(data->file);
	}
	return (i);
}
