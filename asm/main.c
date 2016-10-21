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
	tmp_trad_to_str(&data);
	trad_dir_label(&data);
	final_trad(data, ft_strlen(data->tmp_trad) / 2);
	// show_final_trad(data->tmp_trad); //debug
	create_cor(data, argv[1]);
	return (0);
}
