/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:38:31 by mchevall          #+#    #+#             */
/*   Updated: 2016/12/01 18:38:44 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_f(char **str, int width)
{
	char	*tmp;
	char	i;

	tmp = NULL;
	i = 0;
	if (ft_strlen(*str) == (size_t)width)
		return ;
	while (ft_strlen(*str) < (size_t)width)
	{
		tmp = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin("f", tmp);
		ft_strdel(&tmp);
	}
}
