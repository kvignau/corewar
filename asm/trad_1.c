/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	hex_to_lower(char **hex)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while ((*hex)[i])
	{
		if (ft_isupper((*hex)[i]))
		{
			c = ft_tolower((*hex)[i]);
			(*hex)[i] = c;
		}
		i++;
	}
}

void	trad_reg(char *arg, char **hexa)
{
	char	*tmp;
	char	*zero;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_itoabase_imax(ft_atoi(ft_strsub(arg, 1, ft_strlen(arg))), 16);
	zero = NULL;
	tmp2 = NULL;
	tmp3 = ft_strdup(*hexa);
	ft_strdel(hexa);
	ft_printf("tmp : %s\n, strlen %d", tmp, ft_strlen(tmp));
	if (ft_strlen(tmp) == 1)
	{
		hex_to_lower(&tmp);
		zero = ft_strdup("0");
		tmp2 = ft_strjoin(zero, tmp);
		ft_strdel(&zero);
	}
	else
		tmp2 = ft_strdup(tmp);
	ft_strdel(&tmp);
	(*hexa) = ft_strjoin(tmp3, tmp2);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
	ft_printf("(*hexa) : %s\n", (*hexa));
	// ft_printf("n : %d\n", n);
}

void	trad_dir(char *arg, char **hexa)
{
	ft_putstr("TRAD DIR\n");

}

void	trad_ind(char *arg, char **hexa)
{
	char	*tmp;
	int		i;
	char	*zero;
	char	*new;
	char	*tmp2;

	tmp = NULL;
	i = 0;
	zero = ft_strdup("0");
	new = ft_itoabase_imax(ft_atoi(arg), 16);
	tmp2 = ft_strdup(*hexa);
	ft_strdel(hexa);
	hex_to_lower(&new);
	while (ft_strlen(new) != 4)
	{
		tmp = ft_strdup(new);
		ft_strdel(&new);
		new = ft_strjoin(zero, tmp);
		ft_strdel(&tmp);
		i++;
	}
	(*hexa) = ft_strjoin(tmp2, new);
	ft_strdel(&new);
	ft_strdel(&tmp2);
	ft_strdel(&zero);
}

