/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 18:24:17 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/05 18:24:19 by mchevall         ###   ########.fr       */
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
		if ((error = file_manager(data, i)) != 0)
			return (1);
	}
	else
	{
		ft_putstr("Please provide at least one .s file");
		return (1);
	}
	return (0);
}
