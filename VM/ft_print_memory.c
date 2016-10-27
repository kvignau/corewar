/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:41:58 by kvignau           #+#    #+#             */
/*   Updated: 2016/10/19 14:42:41 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_memory(unsigned char *ptr, int memsize)
{
	int		i;

	i = 0;
	while (i < memsize)
	{
		if (i % 64 == 0)
		{
			if (i != 0)
				write(1, "\n", 1);
			ft_printf("0x%.4x : ", i);
		}
		ft_printf("%.2x ", ptr[i]);
		i++;
	}
	ft_putchar('\n');
}