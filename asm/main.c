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
	t_data	*data;

	i = 0;
	j = -1;
	data_initializer(&data);
	if (argc != 1)
	{
		store_file(argv, data, &i);
		file_manager(data, i);
	}
	else
		error(data, "Please provide a .s file");
	if (!(recovery(data)))
	{
		free_all_data(data);
		return (0);
	}
	tmp_trad_to_str(&data);
	trad_dir_label(&data);
	final_trad(data, ft_strlen(data->tmp_trad) / 2);
	create_cor(data, argv[1]);
	free_all_data(data);
	// while (1);
	return (0);
}
