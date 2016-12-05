/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islabelchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:22:59 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/04 16:24:30 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_islabelchar(int c)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(LABEL_CHARS);
	while (i <= j && c != LABEL_CHARS[i])
		i++;
	if (i < j)
		return (1);
	else
		return (0);
}
