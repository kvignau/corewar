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

void	trad_reg(char *arg, char **hexa, t_data **data)
{
	char	*to_add;
	char	*to_compete;

	(void)data;
	to_add = ft_itoabase_imax(ft_atoi(ft_strsub(arg, 1, ft_strlen(arg))), 16);
	hex_to_lower(&to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	add_zero(&to_add, 2);
	(*hexa) = ft_strjoin(to_compete, to_add);
	ft_strdel(&to_add);
	ft_strdel(&to_compete);
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
	if (arg[1] == ':')
		trad_label(ft_strsub(arg, 2, ft_strlen(arg)), hexa, data);
	else
		trad_ind(ft_strsub(arg, 1, ft_strlen(arg)), hexa, data);
}

void	trad_ind(char *arg, char **hexa, t_data **data)
{
	char	*tmp;
	char	*to_add;
	char	*to_compete;

	(void)data;
	tmp = NULL;
	to_add = ft_itoabase_imax(ft_atoi(arg), 16);
	hex_to_lower(&to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	add_zero(&to_add, 8);
	(*hexa) = ft_strjoin(to_compete, to_add);
	ft_strdel(&to_add);
	ft_strdel(&to_compete);
}

