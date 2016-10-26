/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_trad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	string_to_hex(char *str, char **new)
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

static	void	add_zero_after(char **str, int nb)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	tmp = ft_strdup("0");
	new = NULL;
	add_zero(&tmp, nb - 1 - ft_strlen(*str));
	new = ft_strjoin(*str, tmp);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&new);
}

static	void	concat_all_trad(t_data **data, t_final_trad all_trad)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strjoin(all_trad.magic, all_trad.name);
	tmp1 = ft_strjoin(tmp, all_trad.total_oct);
	ft_strdel(&tmp);
	tmp = ft_strjoin(tmp1, all_trad.comment);
	ft_strdel(&tmp1);
	tmp1 = ft_strjoin(tmp, (*data)->tmp_trad);
	ft_strdel(&tmp);
	ft_strdel(&(*data)->tmp_trad);
	(*data)->tmp_trad = ft_strdup(tmp1);
	ft_strdel(&tmp1);
}

void			final_trad(t_data *data, int nb_oct)
{
	t_final_trad	all_trad;

	ft_bzero(&all_trad, sizeof(t_final_trad));
	all_trad.magic = ft_strdup("00ea83f3");
	string_to_hex(data->name, &all_trad.name);
	add_zero_after(&all_trad.name, 269);
	all_trad.total_oct = ft_itoabase_imax(nb_oct, 16);
	add_zero(&all_trad.total_oct, 4);
	string_to_hex(data->comment, &all_trad.comment);
	add_zero_after(&all_trad.comment, 4105);
	concat_all_trad(&data, all_trad);
	hex_to_lower(&(data->tmp_trad));
}
