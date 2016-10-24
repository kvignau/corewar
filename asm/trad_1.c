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

void	trad_dir_size_2(char *arg, char **hexa, t_data **data, int op_code)
{
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
	to_add = ft_itoabase_imax(ft_atoi(arg), 16);
	hex_to_lower(&to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	add_zero(&to_add, 4);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
}

void	trad_dir_size_4(char *arg, char **hexa, t_data **data, int op_code)
{
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
	to_add = ft_itoabase_imax(ft_atoi(arg), 16);
	hex_to_lower(&to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	add_zero(&to_add, 8);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
}

void	trad_dir_without_label(char *arg, char **hexa, t_data **data, int op_code)
{
	int		size;

	size = op_tab[op_code - 1].lbl_size;
	if (size == 4)
		trad_dir_size_4(arg, hexa, data, op_code);
	else if (size == 2)
		trad_dir_size_2(arg, hexa, data, op_code);

}

static void	tmp_trad_dir_label(char *arg, char **hexa)
{
	char	*tmp;
	char	*tmp1;
	char	*pourcent;

	pourcent = ft_strdup("!");
	tmp = ft_strdup(*hexa);
	ft_strdel(hexa);
	tmp1 = ft_strjoinandfree(arg, pourcent, 2);
	(*hexa) = ft_strjoinandfree(tmp, tmp1, 3);
}

void	trad_dir(char *arg, char **hexa, t_data **data, int op_code)
{
	if (arg[1] == ':')
		tmp_trad_dir_label(arg, hexa);
	else
		trad_dir_without_label(ft_strsub(arg, 1, ft_strlen(arg)), hexa, data, op_code);
}

void	trad_ind(char *arg, char **hexa, t_data **data, int op_code)
{
	char	*tmp;
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
	tmp = NULL;
	ft_putstr("TRAD IND\n");
	ft_printf("arg : %s\n", arg);
	if (arg[0] == '-')
	{
		tmp = ft_strsub(arg, 1, ft_strlen(arg) - 1);
		ft_strdel(&arg);
		arg = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	to_add = ft_itoabase_imax(ft_atoi(arg), 16);
	hex_to_lower(&to_add);
	ft_printf("to_add : %s\n", to_add);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	add_zero(&to_add, 8);
	ft_printf("to_add : %s\n", to_add);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
	ft_printf("(*hexa) : %s\n", (*hexa));

}
