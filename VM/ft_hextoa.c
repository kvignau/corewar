/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 12:09:34 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/20 12:09:41 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*ft_hextoa(int *str, int size)
{
	int		i;
	int		j;
	char	*hex;

	i = 0;
	j = 0;
	hex = (char *)ft_memalloc((size + 1) * sizeof(int));
	while (i < size)
	{
		hex[j] = str[i] >> 24;
		hex[j + 1] = str[i] >> 16;
		hex[j + 2] = str[i] >> 8;
		hex[j + 3] = str[i];
		j += 4;
		i += 2;
	}
	return (hex);
}
