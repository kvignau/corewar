/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:00:35 by kvignau           #+#    #+#             */
/*   Updated: 2016/10/19 14:44:52 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*memory()
{
	char	*plateau;
	int		i;

	i = 0;
	plateau = (char *)malloc(sizeof(char) * (MEM_SIZE * 2));
	while (i < (MEM_SIZE * 2))
	{
		plateau[i] = '0';
		i++;
	}
	return (plateau);
}
