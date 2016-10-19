/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:41:58 by kvignau           #+#    #+#             */
/*   Updated: 2016/10/19 14:42:41 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_memory(char *ptr, int memsize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (memsize * 2))
	{
		if (i == 128)
		{
			write(1, "\n", 1);
			i = 0;
		}
		else if (i != 0 && i % 2 == 0)
			write(1, " ", 1);
		write(1, &ptr[j], 1);
		i++;
		j++;
	}
	write(1, "\n", 1);
}