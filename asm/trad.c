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

void	trad_name_instruct(int op_code, char **hexa)
{
	char		*new;

	ft_putstr("trad_name_instruct\n");
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
	ft_putstr("Trad_args\n");
	while (recup->args_tab[i])
	{
		ft_printf("recup->args_tab[i] : %s\n", recup->args_tab[i]);
		trad = ft_trad[define_trad_fct(recup->args_tab[i])];
		trad(recup->args_tab[i], hexa, data, op_code);
		i++;
	}
}

void	sum_args(t_recup *recup, char **hexa)
{
	int		i;
	int		type;
	int		sum;
	char	*tmp;

	i = 0;
	type = 0;
	sum = 0;
	tmp = NULL;
	if (op_tab[recup->op_code - 1].octcod != 1)
		return ;
	while (recup->args_tab[i])
	{
		type = 0;
		if ((type = define_type_args(recup->args_tab[i])) == 0)
			return ;
		if (i == 0)
			sum = type << 6;
		else if (i == 1)
			sum = sum | (type << 4);
		else if (i == 2)
			sum = sum | (type << 2);
		else
			return ;
		i++;
	}
	tmp = ft_strdup(*hexa);
	ft_strdel(hexa);
	(*hexa) = ft_strjoin(tmp, ft_itoabase_imax(sum, 16));
}

void	trad_to_str(t_data **data)
{
	t_elem	*tmp;
	char	*trad;
	char	*tmp2;
	char	*new;
	char	*label;

	tmp = ((*data)->lst_recup)->tail;
	trad = NULL;
	new = NULL;
	label = NULL;
	ft_printf(">>>>>> STR EN COURS :\n");
	while (tmp != NULL)
	{
		ft_printf("\ntmp de trap debut boucle : %s\n", trad);

		if (trad == NULL)
			tmp2 = ft_strnew(sizeof(char *));
		else
		{
			tmp2 = ft_strdup(trad);
			ft_strdel(&trad);
		}
		if (((t_recup *)((tmp)->content))->lst_hexa)
		{
			new = lsthexa_tostr(((t_recup *)((tmp)->content))->lst_hexa);
			// ft_printf("new : %s\n", new); //debug
			trad = ft_strjoin(tmp2, new);
		}
		else
		{
			// ft_putstr(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			label = ft_strdup(((t_recup *)((tmp)->content))->label_name);
			trad = ft_strjoin(tmp2, label);
			ft_strdel(&label);
			// trad = ft_strdup(tmp2);
		}
		// ft_printf("tmp de trap fin boucle : %s\n", trad); //debug
		ft_strdel(&tmp2);
		ft_strdel(&new);
		tmp = tmp->prev;
	}
	ft_printf("\n FINAL TRAD : %s\n", trad);
	ft_printf("\n");
}
