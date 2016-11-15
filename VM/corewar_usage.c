/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:15:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 18:16:12 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_usage(int argc)
{
	if (argc == 0)
		ft_putstr("Error in usage.\n");
	if (argc < 2)
	{
		ft_putstr("Usage: ./corewar [-d nbr_cycles] [-s] [[-n number]");
		ft_putstr(" <champion1.cor>] <...>\n");
		ft_putstr("There can be a max of only 4 champions\n");
		ft_putstr("-d N    : Dumps memory after N cycles then exits\n");
		ft_putstr("-s      : Stealth mode, does not print 'live' message\n");
		ft_putstr("-n      : Choose champion id\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}
