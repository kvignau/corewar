/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_hexdump.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	reverse_hexdump(char const *trad, int fd)
{
	uintmax_t		value;
	int				i;
	int				len;
	unsigned char	*tmp;

	value = 0;
	i = 0;
	len = ft_strlen(trad);
	while (i < len)
	{
		tmp = (unsigned char *)ft_strsub(trad, i, 2);
		value = ft_hextoi(tmp);
		write(fd, &value, 1);
		ft_strdel((char **)&tmp);
		if (i + 2 < len)
			i += 2;
		else
			break ;
	}
}
