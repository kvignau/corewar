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
	recovery(data);
	tmp_trad_to_str(&data); // debug
	trad_dir_label(&data);
	begin_trad(data);
	show_final_trad(data->tmp_trad);

	return (0);
}
