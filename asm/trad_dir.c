/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		trad_dir_size_2(char *arg, char **hexa, t_data **data,
				int op_code)
{
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
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
	if (ft_strlen(to_add) > 4)
		reduce_hex(&to_add, 4);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
}

static void		trad_dir_size_4(char *arg, char **hexa, t_data **data,
				int op_code)
{
	char	*to_add;
	char	*to_compete;

	(void)data;
	(void)op_code;
	if (arg[0] == '-')
	{
		trad_neg(arg, &to_add);
		add_f(&to_add, 8);
	}
	else
	{
		to_add = ft_itoabase_uimax(ft_atoi(arg), 16);
		add_zero(&to_add, 8);
	}
	hex_to_lower(&to_add);
	if (ft_strlen(to_add) > 8)
		reduce_hex(&to_add, 8);
	to_compete = ft_strdup(*hexa);
	ft_strdel(hexa);
	(*hexa) = ft_strjoinandfree(to_compete, to_add, 3);
}

static void		trad_dir_without_label(char *arg, char **hexa, t_data **data,
			int op_code)
{
	int		size;

	size = op_tab[op_code - 1].lbl_size;
	if (size == 4)
		trad_dir_size_4(arg, hexa, data, op_code);
	else if (size == 2)
		trad_dir_size_2(arg, hexa, data, op_code);
}

static	void	tmp_trad_dir_label(char *arg, char **hexa)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp_char;

	tmp_char = ft_strdup("!");
	tmp = ft_strdup(*hexa);
	ft_strdel(hexa);
	tmp1 = ft_strjoinandfree(arg, tmp_char, 2);
	(*hexa) = ft_strjoinandfree(tmp, tmp1, 3);
}

void			trad_dir(char *arg, char **hexa, t_data **data, int op_code)
{
	if (arg[1] == ':')
		tmp_trad_dir_label(arg, hexa);
	else
		trad_dir_without_label(ft_strsub(arg, 1, ft_strlen(arg)), hexa, data,
		op_code);
}
