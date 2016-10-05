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

#include "asm.h"

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	int		error;
	t_data	*data;

	i = 0;
	j = -1;

	data_initializer(&data);
	if (argc != 1)
	{
		i = store_file(argv, data, i);
		error = file_manager(data, i);
	}
	else
	{
		ft_putstr("Please provide at least one .s file");
		return(1);
	}

	return (0);
}
