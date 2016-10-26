/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*lsthexa_tostr(t_dbllist *lst)
{
	t_elem	*tmp;
	char	*tmp2;
	char	*new;

	tmp = lst->tail;
	tmp2 = NULL;
	new = NULL;
	while (tmp != NULL)
	{
		if (new == NULL)
			tmp2 = ft_strnew(sizeof(char *));
		else
			tmp2 = ft_strdup(new);
		ft_strdel(&new);
		if (((t_hexa *)((tmp)->content))->hexa)
			new = ft_strjoin(tmp2, ((t_hexa *)((tmp)->content))->hexa);
		tmp = tmp->prev;
	}
	return (new);
}

void	trad_name_instruct(int op_code, char **hexa)
{
	char		*new;

	new = ft_itoabase_imax(op_code, 16);
	hex_to_lower(&new);
	add_zero(&new, 2);
	(*hexa) = ft_strdup(new);
	ft_strdel(&new);
}

void	trad_args(t_recup *recup, char **hexa, t_data **data, int op_code)
{
	int						i;
	static const t_trad		ft_trad[] = {trad_reg, trad_dir, trad_ind};
	t_trad					trad;

	recup->lst_hexa = ft_lstdblnew();
	i = 0;
	while (recup->args_tab[i])
	{
		trad = ft_trad[define_trad_fct(recup->args_tab[i])];
		trad(recup->args_tab[i], hexa, data, op_code);
		i++;
	}
}

void	sum_args(t_recup *recup, char **hexa)
{
	int			i;
	t_sum_args	data;
	char		*tmp;

	i = 0;
	ini_sum_args(&data);
	tmp = NULL;
	while (recup->args_tab[i])
	{
		data.type = 0;
		if ((data.type = args_for_sum(recup->args_tab[i])) == 0)
			return ;
		if (i == 0)
			data.sum = data.type << 6;
		else if (i == 1)
			data.sum = data.sum | (data.type << 4);
		else if (i == 2)
			data.sum = data.sum | (data.type << 2);
		else
			return ;
		i++;
	}
	tmp = ft_strdup(*hexa);
	ft_strdel(hexa);
	(*hexa) = ft_strjoinandfree(tmp, ft_itoabase_imax(data.sum, 16), 3);
}

void	tmp_trad_to_str(t_data **data)
{
	t_elem	*tmp;
	t_tmp1	temp;

	tmp = ((*data)->lst_recup)->tail;
	ini_tmp1(&temp);
	while (tmp != NULL)
	{
		if ((*data)->tmp_trad == NULL)
			temp.tmp2 = ft_strnew(sizeof(char *));
		else
		{
			temp.tmp2 = ft_strdup((*data)->tmp_trad);
			ft_strdel(&(*data)->tmp_trad);
		}
		if (((t_recup *)((tmp)->content))->lst_hexa)
		{
			temp.nw = lsthexa_tostr(((t_recup *)((tmp)->content))->lst_hexa);
			(*data)->tmp_trad = ft_strjoinandfree(temp.tmp2, temp.nw, 2);
		}
		else
			(*data)->tmp_trad = ft_strdup(temp.tmp2);
		ft_strdel(&temp.tmp2);
		tmp = tmp->prev;
	}
}
