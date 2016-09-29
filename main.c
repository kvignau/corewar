/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	t_data	*data;

	i = 0;
	j = -1;

	data_initializer(&data);
	if (argc != 1)
		i = store_file(argv, data, i);
	else
	{
		ft_putstr("Please provide at least one .s file");
		return(1);
	}
	while (j++ < i)
		ft_printf("[%d]: %s \n", j, data->file[j]);
	return (0);
}

