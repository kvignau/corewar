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
	char		*tmp;
	char		*zero;

	ft_putstr("trad_name_instruct\n");
	tmp = ft_itoabase_imax(op_code, 16);
	hex_to_lower(&tmp);
	zero = ft_strdup("0");
	if (ft_strlen(tmp) == 1)
		(*hexa) = ft_strjoin(zero, tmp);
	else
		(*hexa) = ft_strdup(tmp);
	ft_strdel(&zero);
	ft_strdel(&tmp);
	// ft_printf("(*hexa) %s\n", (*hexa));
	// ft_lstdbladd_head(recup->lst_hexa, &hex, sizeof(t_hexa));
	// show_lst_hexa(recup->lst_hexa);

}

void	trad_args(t_recup *recup, char **hexa, t_data **data)
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
		trad(recup->args_tab[i], hexa, data);
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
