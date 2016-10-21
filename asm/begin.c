/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	string_to_hex(char *str, char **new)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	i = 0;
	tmp = NULL;
	tmp1 = NULL;
	while (str[i])
	{
		tmp = ft_itoabase_imax(str[i], 16);
		ft_printf("tmp : %s\n", tmp);
		if (*new == NULL)
			*new = ft_strdup(tmp);
		else
		{
			tmp1 = ft_strdup(*new);
			ft_strdel(new);
			*new = ft_strjoin(tmp1, tmp);
		}
		i++;
	}
}

void	add_zero_after(char **str, int nb)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	tmp = ft_strdup("0");
	new = NULL;
	add_zero(&tmp, nb - 1);
	new = ft_strjoin(*str, tmp);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&new);
}

void	begin_trad(t_data *data)
{
	char	*name;
	char	*comment;
	char	*magic;

	name = NULL;
	comment = NULL;
	magic = ft_strdup("00ea83f3");
	string_to_hex(data->name, &name);
	add_zero_after(&name, 270);
	string_to_hex(data->comment, &comment);
	add_zero_after(&comment, 4106); // ajouter le nombre doctet total
}
