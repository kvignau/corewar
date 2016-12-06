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

unsigned char		*memory(void)
{
	unsigned char	*plateau;

	plateau = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (MEM_SIZE));
	return (plateau);
}
