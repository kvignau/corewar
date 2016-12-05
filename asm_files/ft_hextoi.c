/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:47:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/18 14:47:56 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uintmax_t	ft_mini_power(int nb, int power)
{
	uintmax_t	value;

	value = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 0)
	{
		value *= nb;
		power--;
	}
	return (value);
}

uintmax_t			ft_hextoi(unsigned char *str)
{
	int					i;
	int					j;
	int					len;
	uintmax_t			value;

	len = ft_strlen((char *)str) - 1;
	i = 0;
	j = 0;
	value = 0;
	while (len >= 0)
	{
		if (str[len] >= 48 && str[len] <= 57)
			j = str[len] - 48;
		else if (str[len] >= 97 && str[len] <= 102)
			j = str[len] - 87;
		value = value + j * (ft_mini_power(16, i));
		len--;
		i++;
	}
	return (value);
}
