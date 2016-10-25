/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:50:00 by kvignau           #+#    #+#             */
/*   Updated: 2016/10/25 16:50:02 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	*addzero(char *str, int len)
{
	int		size;

	size = len - ft_strlen(str);
	while (size > 0)
	{
		str = ft_strjoinandfree("0", str, 2);
		size--;
	}
	return (str);
}

char		*get_content(int *str, int size)
{
	char	*content;
	char	*nb;
	int		i;
	int		len;

	content = (char *)ft_memalloc(1);
	i = 0;

	while (size > 0)
	{
		if (size >= 8)
			len = 8;
		else
			len = size;
		nb = addzero(ft_itoabase_uimax((unsigned int)str[i], 16), len);
		content = ft_strjoinandfree(content, nb, 3);
		i += 2;
		size -= 8;
	}
	return (content);
}
