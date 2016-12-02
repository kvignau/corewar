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

static	void	string_to_hex_case(char *tmp1, char *tmp, char **new)
{
	tmp1 = ft_strdup(*new);
	ft_strdel(new);
	*new = ft_strjoinandfree(tmp1, tmp, 1);
}

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
		if (ft_strlen(tmp) < 2)
		{
			tmp1 = tmp;
			add_zero(&tmp, 2);
			free(tmp1);
		}
		if (*new == NULL)
			*new = ft_strdup(tmp);
		else
			string_to_hex_case(tmp1, tmp, new);
		if (tmp != NULL)
			ft_strdel(&tmp);
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
	if (*str == NULL)
		*str = ft_strdup("");
	add_zero(&tmp, nb - 1 - ft_strlen(*str));
	new = ft_strjoinandfree(*str, tmp, 3);
	*str = ft_strdup(new);
	ft_strdel(&new);
}

static	void	concat_all_trad(t_data **data, t_final_trad all_trad)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strjoinandfree(all_trad.magic, all_trad.name, 3);
	tmp1 = ft_strjoinandfree(tmp, all_trad.total_oct, 3);
	tmp = ft_strjoinandfree(tmp1, all_trad.comment, 3);
	tmp1 = ft_strjoinandfree(tmp, (*data)->tmp_trad, 3);
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
