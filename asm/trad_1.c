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

void	trad_reg(char *arg, char **hexa, t_data **data)
{
	char	*tmp;
	char	*zero;
	char	*tmp2;
	char	*tmp3;

	(void)data;
	tmp = ft_itoabase_imax(ft_atoi(ft_strsub(arg, 1, ft_strlen(arg))), 16);
	hex_to_lower(&tmp);
	zero = NULL;
	tmp2 = NULL;
	tmp3 = ft_strdup(*hexa);
	ft_strdel(hexa);
	// ft_printf("tmp : %s\n, strlen %d", tmp, ft_strlen(tmp));
	if (ft_strlen(tmp) == 1)
	{
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
	// ft_printf("(*hexa) : %s\n", (*hexa));
	// ft_printf("n : %d\n", n);
}

void	trad_label(char *name, char **hexa, t_data **data)
{
	char	*tmp;
	char	*unknw;

	tmp = NULL;
	unknw = NULL;
	ft_printf("TRAD LABEL\n");
	if (!(exist_label(name, data)))
		return ;
	unknw = ft_strdup("XXXX");
	tmp = ft_strdup(*hexa);
	ft_strdel(hexa);
	(*hexa) = ft_strjoin(tmp, unknw);
	ft_strdel(&tmp);
	ft_strdel(&unknw);

}

void	trad_dir(char *arg, char **hexa, t_data **data)
{
	ft_putstr("TRAD DIR\n");
	int		i;

	i = 1;
	if (arg[i] == ':')
		trad_label(ft_strsub(arg, 2, ft_strlen(arg)), hexa, data);
	else
		trad_ind(ft_strsub(arg, 1, ft_strlen(arg)), hexa, data);
}

void	trad_ind(char *arg, char **hexa, t_data **data)
{
	char	*tmp;
	int		i;
	char	*zero;
	char	*new;
	char	*tmp2;

	(void)data;
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
