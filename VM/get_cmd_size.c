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

int		param_3(int nb_param, int *type, int label_size, int size)
{
	if (nb_param == 3)
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

int		get_cmd_size(int *type, int label_size, int nb_param)
{
	int		size;

	size = 2;
	if (nb_param >= 1)
	{
		if (type[0] == REG)
			size += 1;
		else if (type[0] == DIR)
			size += label_size;
		else if (type[0] == IND)
			size += 2;
	}
	if (nb_param >= 2)
	{
		if (type[1] == REG)
			size += 1;
		else if (type[1] == DIR)
			size += label_size;
		else if (type[1] == IND)
			size += 2;
	}
	size = param_3(nb_param, type, label_size, size);
	free(type);
	return (size);
}
