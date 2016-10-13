/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:48:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 18:15:04 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_cor		core;
	t_options	options;
	t_dbllist	*champ_list;

	ft_bzero(&core, sizeof(t_cor));
	ft_bzero(&options, sizeof(t_options));
	champ_list = ft_lstdblnew();
	if (!corewar_usage(argc))
		return (-1);
	options_checkers(argc, argv, &options, champ_list);
	ft_printf("dump: %d\ndump_N : %u\nchampnum: %d\nchamp_N: %d\nS: %d\n", options.dump, options.dump_N, options.number, options.number_N, options.stealth);
	//champions_checkers();

	return (0);
}
