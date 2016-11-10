/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:28:28 by mchevall          #+#    #+#             */
/*   Updated: 2016/11/10 15:28:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_cmd_size(int *type, int label_size)
{
	int		size;

	size = 0;
	if (type[0] == REG)
		size += 1;
	else if (type[0] == DIR)
		size += label_size;
	else if (type[0] == IND)
		size += 2;
	if (type[1] == REG)
		size += 1;
	else if (type[1] == DIR)
		size += label_size;
	else if (type[1] == IND)
		size += 2;
	if (type[2])
	{
		if (type[2] == REG)
			size += 1;
		else if (type[2] == DIR)
			size += label_size;
		else if (type[2] == IND)
			size += 2;
	}
	return (size);
}

