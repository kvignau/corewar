/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_reg_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_f(char **str, int width)
{
	char	*tmp;
	char	i;

	tmp = NULL;
	i = 0;
	if (ft_strlen(*str) == width)
		return ;
	while (ft_strlen(*str) < width)
	{
		tmp = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin("f", tmp);
		ft_strdel(&tmp);
	}
}

void	trad_neg(char *arg, char **to_add)
{
	int		n;
	char	*tmp;

	tmp = ft_strsub(arg, 1, ft_strlen(arg) - 1);
	n = ft_atoi(tmp);
	ft_strdel(&tmp);
	*to_add = ft_strdup(ft_itoabase_uimax(65536 - n, 16));
}

void	trad_reg(char *arg, char **hexa, t_data **data, int op_code)
{
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
	to_add = ft_itoabase_imax(ft_atoi(ft_strsub(arg, 1, ft_strlen(arg))), 16);
	hex_to_lower(&to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	add_zero(&to_add, 2);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
}

void	reduce_hex(char **to_add, int size)
{
	char	*tmp;

	tmp = ft_strsub(*to_add, ft_strlen(*to_add) - size, ft_strlen(*to_add));
	ft_strdel(to_add);
	*to_add = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	trad_ind(char *arg, char **hexa, t_data **data, int op_code)
{
	char	*tmp;
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
	tmp = NULL;
	if (arg[0] == '-')
	{
		trad_neg(arg, &to_add);
		add_f(&to_add, 4);
	}
	else
	{
		to_add = ft_itoabase_uimax(ft_atoi(arg), 16);
		add_zero(&to_add, 4);
	}
	hex_to_lower(&to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
}
